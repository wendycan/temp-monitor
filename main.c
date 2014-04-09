/*
 * main.c
 */

#include "msp430f5529.h"
#include "HAL_Dogs102x6.h"
#include "config.h"

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
void Delay(unsigned char i){
	while(i--)
	{
		Delay400ms();
	}
}
void main(void) {
	uint8_t contrast;            //读取FLASH中对比度值
	uint8_t brightness;        //读取FLASH中背光值
	WDTCTL = WDTPW + WDTHOLD;
    Dogs102x6_init();                            //初始化LCD
    Dogs102x6_backlightInit();                   //背光初始化

    // Contrast not programed in Flash Yet
    if (contrast == 0xFF)                        //若当前FLASH中无对比度值，则将对比度值设为11（默认）
        // Set Default Contrast
        contrast = 11;

    // Brightness not programed in Flash Yet
    if (brightness == 0xFF)                      //若当前FLASH中无背光值，则将背光值设为11（默认）
        // Set Default Brightness
        brightness = 11;

    Dogs102x6_setBacklight(brightness);          //设置初始背光值
    Dogs102x6_setContrast(contrast);             //设置初始对比度值
    Dogs102x6_clearScreen();                     //清屏
    //Dogs102x6_imageDraw(tiBug, 0, 16);           //显示TI图案
    Dogs102x6_stringDraw(3, 0, "   Welcome to    ", DOGS102x6_DRAW_NORMAL);
    Delay(10);

}
