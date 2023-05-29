// Registers & Bits
	#define NABUduino_Reg_Base							0xC0
	#define NABUduino_Reg_Command						(NABUduino_Reg_Base+0x09)	// When written to from the Z80
	#define NABUduino_Reg_Status						(NABUduino_Reg_Base+0x09)	// When read from by the Z80
	#define NABUduino_Reg_Data							(NABUduino_Reg_Base+0x08)
	#define NABUduino_Reg_Sync							(NABUduino_Reg_Base+0x0A)

	#define NABUduino_SyncMask_FromZ80					0x01
	#define NABUduino_SyncMask_ToZ80					0x02

// Commands
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

// Status
	#define NABUduinoStatus_Idle						0x00
	#define NABUduinoStatus_StartOfData					0x01
	#define NABUduinoStatus_Data						0x02
	#define NABUduinoStatus_EndOfData					0x03
	#define NABUduinoStatus_Error						0xFF

// Debugging utility.
uint8_t HexLUT[]="0123456789ABCDEF";
static inline void printHex(uint8_t value)
{
	vdp_write(HexLUT[value >> 4], 1);
	vdp_write(HexLUT[value & 0x0F], 1);
}


static uint8_t NABUduino_ReadDataByte()
{
	while(!(z80_inp(NABUduino_Reg_Sync) & NABUduino_SyncMask_ToZ80));	// Wait for the NABUduino to return a result
	return z80_inp(NABUduino_Reg_Data);
}

static void NABUduino_EatDataBytesUntilIdle()
{
	uint8_t count=0;
	uint8_t status=z80_inp(NABUduino_Reg_Status);

	while(status!=NABUduinoStatus_Idle)
	{
		z80_inp(NABUduino_Reg_Data);
		status=z80_inp(NABUduino_Reg_Status);
	};
	z80_inp(NABUduino_Reg_Data);
}

// Soft-resets the NABUduino and clears it's communication registers
void NABUduino_init()
{
	z80_outp(NABUduino_Reg_Command, NABUduinoCommand_Reset);
	z80_outp(NABUduino_Reg_Data, 0x00);
	
	z80_delay_ms(100);				// Wait for the NABUduino to perform the soft-reset.
		
	z80_inp(NABUduino_Reg_Data);	// Clear the NABUduino's output register
}

void showState(uint8_t state)
{
	vdp_setCursor2(0, 10);
	vdp_write(HexLUT[state], 1);
}

typedef struct
{
	uint16_t x;
	uint16_t y;
	uint8_t buttons;
} MousePosition;

MousePosition mousePosition;
uint8_t NABUduino_ReadMouse()
{
	uint8_t status=z80_inp(NABUduino_Reg_Status);
	
	if(status==NABUduinoStatus_Error) return NABUduinoStatus_Error; // Check to see if an error has occurred.
	NABUduino_EatDataBytesUntilIdle();	// Clear any dangling bytes.

	while(z80_inp(NABUduino_Reg_Sync) & NABUduino_SyncMask_FromZ80);	// Wait for the NABUduino's input registers to be available...
	z80_outp(NABUduino_Reg_Command, NABUduinoCommand_ReadMouse);
	z80_outp(NABUduino_Reg_Data, 0x00);
	
	mousePosition.x=NABUduino_ReadDataByte();
	mousePosition.x|=(((uint16_t)NABUduino_ReadDataByte()) << 8);
	mousePosition.y=NABUduino_ReadDataByte();
	mousePosition.y|=(((uint16_t)NABUduino_ReadDataByte()) << 8);
	mousePosition.buttons=NABUduino_ReadDataByte();
	
	NABUduino_EatDataBytesUntilIdle();
	
	return z80_inp(NABUduino_Reg_Status);
}

uint8_t NABUduino_OutputString(char *string)
{
	if(z80_inp(NABUduino_Reg_Status)) return NABUduinoStatus_Error; // If the NNABUduino is not idle, an error has occurred.
	z80_inp(NABUduino_Reg_Data);  // Clear the NABUduino's output registers, just in case...

	while(z80_inp(NABUduino_Reg_Sync) & NABUduino_SyncMask_FromZ80);	// Wait for the NABUduino's input registers to be available...
	
	z80_outp(NABUduino_Reg_Command, NABUduinoCommand_OutputSerial);
	z80_outp(NABUduino_Reg_Data, *string);
	while(*(++string))
	{
		while(z80_inp(NABUduino_Reg_Sync) & NABUduino_SyncMask_FromZ80);	// Wait for the NABUduino's input registers to be available...
		z80_outp(NABUduino_Reg_Data, *string);
	}
	while(z80_inp(NABUduino_Reg_Sync) & NABUduino_SyncMask_FromZ80);	// Wait for the NABUduino's input registers to be available...
	z80_outp(NABUduino_Reg_Data, 0x00); // End of string marker
	
	while(!(z80_inp(NABUduino_Reg_Sync) & NABUduino_SyncMask_ToZ80));	// Wait for the NABUduino's output registers to have data...
	uint8_t status=z80_inp(NABUduino_Reg_Status);
	uint8_t data=z80_inp(NABUduino_Reg_Data);

	return status;
}
