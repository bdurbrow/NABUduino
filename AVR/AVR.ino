// NABUduino AVR Firmware

#include <SPI.h>
#include "SdFat.h"
#include "sdios.h"

SdFat32 sd;
File32 file;

#include "PS2MouseHandler.h"
#define MOUSE_DATA									15
#define MOUSE_CLOCK									14

PS2MouseHandler mouse(MOUSE_CLOCK, MOUSE_DATA, PS2_MOUSE_REMOTE);
uint8_t mouseInitStatus;
int16_t mouseCursorX;
int16_t mouseCursorY;

#define MOUSE_CURSOR_LIMIT_X						(0x30000)
#define MOUSE_CURSOR_LIMIT_Y						(0x30000)

#define Z80ReadSyncPort								PORTC
#define Z80WriteSyncPort							PORTD
#define SerialInPort								PORTB
#define SerialOutPort								PORTD
#define SerialInRegistersAreEmptyPort				PORTB
#define SerialOutEndOfFramePort						PORTD
#define SerialClockPort								PORTD

#define Z80ReadSyncPin								PINC
#define Z80WriteSyncPin								PIND
#define SerialInPin									PINB
#define SerialOutPin								PIND
#define SerialInRegistersAreEmptyPin				PINB
#define SerialOutEndOfFramePin						PIND
#define SerialClockPin								PIND

#define Z80ReadSyncBit								2
#define Z80WriteSyncBit								4
#define SerialInBit									1
#define SerialOutBit								5
#define SerialInRegistersAreEmptyBit				0
#define SerialOutEndOfFrameBit						6
#define SerialInClockBit							3
#define SerialOutClockBit							7

#define Z80ReadSyncArduinoDigitalPin				16
#define Z80WriteSyncArduinoDigitalPin				4
#define SerialInArduinoDigitalPin					9
#define SerialOutArduinoDigitalPin					5
#define SerialInRegistersAreEmptyArduinoDigitalPin	8
#define SerialOutEndOfFrameArduinoDigitalPin		6
#define SerialInClockArduinoDigitalPin				3
#define SerialOutClockArduinoDigitalPin				7

#define NABUduinoCommand_Parameter					0x00
#define NABUduinoCommand_Reset						0x01
#define NABUduinoCommand_Idle						0x02
#define NABUduinoCommand_ShutDown					0x0F

#define NABUduinoCommand_ReadMouse					0x10

#define NABUduinoCommand_ReadBlock					0x20
#define NABUduinoCommand_WriteBlock					0x21
#define NABUduinoCommand_ListImages					0x22
#define NABUduinoCommand_MountImage					0x23
#define NABUduinoCommand_UnmountImage				0x24
#define NABUduinoCommand_NewImage					0x25

#define NABUduinoCommand_OutputSerial				0x30

#define NABUduinoStatus_Idle						0x00
#define NABUduinoStatus_StartOfData					0x01
#define NABUduinoStatus_Data						0x02
#define NABUduinoStatus_EndOfData					0x03
#define NABUduinoStatus_Error						0xFF


#define NABUduinoReturnStatus_OK					0x00
#define NABUduinoReturnStatus_Reset					0x01
#define NABUduinoReturnStatus_Error					0xFF


#define NABUduino_IODelay()		delayMicroseconds(2)

void setup()
{
	pinMode(Z80ReadSyncArduinoDigitalPin, INPUT);
	pinMode(Z80WriteSyncArduinoDigitalPin, INPUT);
	pinMode(SerialInArduinoDigitalPin, INPUT);
	pinMode(SerialOutArduinoDigitalPin, OUTPUT);
	pinMode(SerialInRegistersAreEmptyArduinoDigitalPin, OUTPUT);
	pinMode(SerialOutEndOfFrameArduinoDigitalPin, OUTPUT);
	pinMode(SerialInClockArduinoDigitalPin, OUTPUT);
	pinMode(SerialOutClockArduinoDigitalPin, OUTPUT);

	pinMode(LED_BUILTIN, OUTPUT);

	SerialOutPort &=~ _BV(SerialOutBit);
	SerialInRegistersAreEmptyPort |= _BV(SerialInRegistersAreEmptyBit);
	SerialOutEndOfFramePort &=~ _BV(SerialOutEndOfFrameBit);
	SerialClockPort &=~ _BV(SerialInClockBit);
	SerialClockPort &=~ _BV(SerialOutClockBit);
	
	Serial.begin(57600);
	Serial.println("Nabuduino Starting up...");

	Serial.println("Will init mouse...");
	mouseInitStatus=mouse.initialise();
  if(!mouseInitStatus)
  {
		Serial.println(" Found one.");
  }
}

// Note: the command register is cleared to 0x00 by the reading process;
// so just sending multiple bytes to the data register will result in NABUduinoCommand_Parameter
// being read for the subsequent bytes.

void read16(uint8_t &data, uint8_t &command)
{
	uint8_t oldSREG = SREG;
	cli();

	SerialClockPort &=~ _BV(SerialInClockBit); NABUduino_IODelay(); // Make sure the clock pin starts out low...

	// Shift in the data byte
		data=((SerialInPin & _BV(SerialInBit))?1:0);
		for(uint8_t count=7; count; count--)
		{
			SerialClockPort |= _BV(SerialInClockBit); NABUduino_IODelay(); SerialClockPort &=~ _BV(SerialInClockBit); NABUduino_IODelay();
			data=(data << 1) | ((SerialInPin & _BV(SerialInBit))?1:0);
		}

	// Shift in the command byte
		SerialClockPort |= _BV(SerialInClockBit); NABUduino_IODelay(); SerialClockPort &=~ _BV(SerialInClockBit); NABUduino_IODelay();
		command=((SerialInPin & _BV(SerialInBit))?1:0);
		for(uint8_t count=7; count; count--)
		{
			SerialClockPort |= _BV(SerialInClockBit); NABUduino_IODelay(); SerialClockPort &=~ _BV(SerialInClockBit); NABUduino_IODelay();
			command=(command << 1) | ((SerialInPin & _BV(SerialInBit))?1:0);
		}

	// Pulse Input Registers Are Empty line 
		SerialInRegistersAreEmptyPort |= _BV(SerialInRegistersAreEmptyBit); NABUduino_IODelay(); SerialInRegistersAreEmptyPort &=~ _BV(SerialInRegistersAreEmptyBit); NABUduino_IODelay(); SerialInRegistersAreEmptyPort |= _BV(SerialInRegistersAreEmptyBit);

	SREG = oldSREG;

  // Debugging code. Un-comment to send the incoming command & data bytes to the serial port as ASCII hex.
  // Serial.print(">");
  // Serial.print(command, HEX);
  // Serial.print(",");
  // Serial.println(data, HEX);
}

void write16(uint8_t data, uint8_t status)
{
  // Debugging code. Un-comment to send the incoming command & status bytes to the serial port as ASCII hex.
  // Serial.print(">");
  // Serial.print(command, HEX);
  // Serial.print(",");
  // Serial.println(status, HEX);

	uint8_t oldSREG = SREG;
	cli();
	
	SerialClockPort &=~ _BV(SerialOutClockBit); NABUduino_IODelay(); // Make sure the clock pin starts out low...
	
	// Shift out the status byte
		for(uint8_t count=8; count; count--)
		{
			if(status & 0x80) SerialOutPort |= _BV(SerialOutBit); else SerialOutPort &=~ _BV(SerialOutBit); NABUduino_IODelay();
			SerialClockPort |= _BV(SerialOutClockBit); NABUduino_IODelay(); SerialClockPort &=~ _BV(SerialOutClockBit); NABUduino_IODelay();
			status = status << 1;
		}
		
	// Shift out the data byte
		for(uint8_t count=8; count; count--)
		{
			if(data & 0x80) SerialOutPort |= _BV(SerialOutBit); else SerialOutPort &=~ _BV(SerialOutBit); NABUduino_IODelay();
			SerialClockPort |= _BV(SerialOutClockBit); NABUduino_IODelay(); SerialClockPort &=~ _BV(SerialOutClockBit); NABUduino_IODelay();
			data = data << 1;
		}
	
	// Toggle End of Frame
		NABUduino_IODelay(); SerialOutEndOfFramePort &=~ _BV(SerialOutEndOfFrameBit); NABUduino_IODelay(); SerialOutEndOfFramePort |= _BV(SerialOutEndOfFrameBit); NABUduino_IODelay(); SerialOutEndOfFramePort &=~ _BV(SerialOutEndOfFrameBit); NABUduino_IODelay();
		
	SREG = oldSREG;
}

static inline uint8_t readCommandParameter_(uint8_t &parameterData)
{
	while(!(Z80WriteSyncPin & _BV(Z80WriteSyncBit)));
	uint8_t receivedCommand;
	read16(parameterData, receivedCommand);
	if(receivedCommand != NABUduinoCommand_Parameter)
	{
		if(receivedCommand == NABUduinoCommand_Reset)
		{
			return NABUduinoReturnStatus_Reset;
		}
		else
		{
			write16(0, NABUduinoStatus_Error);
			return NABUduinoReturnStatus_Error;
		}
	}
	
	return NABUduinoReturnStatus_OK;
}

#define readCommandParameter(parameterData)																			\
		{																											\
			uint8_t result=readCommandParameter_(parameterData);													\
			if(result)																								\
			{																										\
				if(result==NABUduinoCommand_Reset) goto performReset;												\
				else goto handleError;																				\
			}																										\
		}																											\


static inline void writeWhenReady(uint8_t data, uint8_t status)
{
	while(Z80ReadSyncPin & _BV(Z80ReadSyncBit));
	write16(data,status);																						
}

static inline void goIdleWhenReady()
{
	while(Z80ReadSyncPin & _BV(Z80ReadSyncBit));
	write16(0x00,NABUduinoStatus_Idle);																						
}

unsigned long last_run = millis();

void loop()
{
	if(((millis() - last_run) > 20) && (mouseInitStatus==0))
	{
		last_run = millis();
		mouse.get_data();

		{
		  register int movementX=mouse.x_movement();
		  register int result=mouseCursorX+movementX;
		  if(result<0)
		  {
			result=0;
		  }
		  else if(result>MOUSE_CURSOR_LIMIT_X)
		  {
			result=MOUSE_CURSOR_LIMIT_X;
		  }
		  mouseCursorX=result;
		}

		{
		  register int movementY=mouse.y_movement();
		  register int result=mouseCursorY-movementY;
		  if(result<0)
		  {
			result=0;
		  }
		  else if(result>MOUSE_CURSOR_LIMIT_Y)
		  {
			result=MOUSE_CURSOR_LIMIT_Y;
		  }
		  mouseCursorY=result;
		}
	}

	if(Z80WriteSyncPin & _BV(Z80WriteSyncBit))
	{
		uint8_t command=0;
		uint8_t data=0;
		read16(data, command);

		// Debugging code: uncomment to send the command & data bytes to the serial port.
		// Serial.print(command,HEX);
		// Serial.print(":");
		// Serial.println(data,HEX);

		switch(command)
		{
			case NABUduinoCommand_Reset:
				goto performReset;
			break;
				
			case NABUduinoCommand_Idle:
			break;

			case NABUduinoCommand_ShutDown:
			break;

			case NABUduinoCommand_ReadMouse:
				writeWhenReady(mouseCursorX & 0xFF, NABUduinoStatus_StartOfData);
				writeWhenReady(mouseCursorX >> 8, NABUduinoStatus_Data);
				writeWhenReady(mouseCursorY & 0xFF, NABUduinoStatus_Data);
				writeWhenReady(mouseCursorY >> 8, NABUduinoStatus_Data);
				writeWhenReady(mouse.status() & 0x07, NABUduinoStatus_EndOfData);
				goIdleWhenReady();
			break;

			case NABUduinoCommand_ReadBlock:
			break;

			case NABUduinoCommand_WriteBlock:
			break;

			case NABUduinoCommand_ListImages:
			break;

			case NABUduinoCommand_MountImage:
			break;

			case NABUduinoCommand_UnmountImage:
			break;

			case NABUduinoCommand_NewImage:
			break;
				
			case NABUduinoCommand_OutputSerial:
				digitalWrite(LED_BUILTIN, HIGH);
				if(data)
				{
					Serial.write(data);
					do
					{
						readCommandParameter(data);
						if(data) Serial.write(data);
					} while(data);
				}
				digitalWrite(LED_BUILTIN, LOW);
				goIdleWhenReady();
			break;

				
			default: break;
		}
	}
	
	return;
	
	performReset:
		write16(0,NABUduinoStatus_Idle);
	  // Pulse Input Registers Are Empty line
		SerialInRegistersAreEmptyPort &=~ _BV(SerialInRegistersAreEmptyBit); NABUduino_IODelay(); SerialInRegistersAreEmptyPort |= _BV(SerialInRegistersAreEmptyBit);
		SerialInRegistersAreEmptyPort &=~ _BV(SerialInRegistersAreEmptyBit); NABUduino_IODelay(); SerialInRegistersAreEmptyPort |= _BV(SerialInRegistersAreEmptyBit);
		Serial.println("\n\nDid soft reset...");
		return;
		
	handleError:
		Serial.print("\n\nError.");
		write16(0, NABUduinoStatus_Error);
		return;
}
