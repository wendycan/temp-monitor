/*
 * main.c
 */

#include "msp430f5529.h"
#include "HAL_Dogs102x6.h"
#include "config.h"

void InitLcd(void);
void InitAll(void);
void Delay400ms(void);
void Delay(unsigned char i);

void main(void) {
	WDTCTL = WDTPW + WDTHOLD;
	InitAll();
    //Dogs102x6_imageDraw(Dlogo, 0, 16);           //Display logo
    Dogs102x6_stringDraw(3, 0, "   Welcome to    ", DOGS102x6_DRAW_NORMAL);
    Delay(10);
}

void InitAll(void){
	InitLcd();
}

void InitLcd(){
    Dogs102x6_init();                            //Init LCD
    Dogs102x6_backlightInit();                   //Init backlight

    Dogs102x6_setBacklight(Dbrightness);          //Set backlight value
    Dogs102x6_setContrast(Dcontrast);             //Set contrast value
    Dogs102x6_clearScreen();                     //Clear screen
}

void Delay400ms(void)
{
    unsigned char i=500;
	unsigned int j;

	while(i--)
	{
		j=7269;
		while(j--);
	}
}

void Delay(unsigned char n){
	while(n--)
	{
		Delay400ms();
	}
}
