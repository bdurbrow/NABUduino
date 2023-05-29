#define BIN_TYPE BIN_HOMEBREW

static void orgit() __naked
{
	__asm
	org	  0x140D
	nop
	nop
	nop
	__endasm;
}

void main2();

void main()
{
	main2();
}

#include "../NABULIB/NABU-LIB.h"

#include "NABUduino.h"

typedef struct
{
		uint8_t x;
		uint8_t y;
} TextPosition;

void main2()
{
	// Set the text mode to foreground color white, bg black
	vdp_initTextMode(0x01, 0x03);

	//z80_delay_ms(1000);

	// Reset the NABUduino
	NABUduino_init();

	TextPosition newPosition;
	TextPosition lastPosition;

	lastPosition.x = 0;
	lastPosition.y = 0;

	while (true)
	{
		uint8_t status=NABUduino_ReadMouse();
		vdp_setCursor2(0, 0);
		printHex(status);

		newPosition.x=mousePosition.x>>8;
		newPosition.y=mousePosition.y>>8;

		
		if(newPosition.x>39) newPosition.x=39;
		if(newPosition.y>22) newPosition.y=22;
	
		vdp_setCursor2(3, 0);
		printHex(mousePosition.x >> 8);
		printHex(mousePosition.x & 0xFF);
		vdp_setCursor2(8, 0);
		printHex(mousePosition.y >> 8);
		printHex(mousePosition.y & 0xFF);
		vdp_setCursor2(13, 0);
		printHex(mousePosition.buttons);

		if((lastPosition.x != newPosition.x) || (lastPosition.y != newPosition.y))
		{
			// Move the cursor to the last position that we were and erase what was there
			vdp_setCursor2(lastPosition.x, lastPosition.y+1);
			vdp_print(" ");

			// Write the text in the new position
			vdp_setCursor2(newPosition.x, newPosition.y+1);
			vdp_print("*");

			// Save the new position into the last position
			lastPosition.x = newPosition.x;
			lastPosition.y = newPosition.y;	 
		}
			
		static uint8_t count=0;
		vdp_setCursor2(36, 0);
		printHex(count++);
	}
}
