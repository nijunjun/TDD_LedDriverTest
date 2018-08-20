/*
 * led_status_ctrl.c
 * 本文用于对LED驱动控制进行具体实现，基于《测试驱动的嵌入式C语言开发》第3章进行设计
 *
 *  Created on: 2018年8月17日
 *      Author: NJ
 */

#include "led_status_ctrl.h"

//宏定义区域

//变量声明
static uint16_t *ledsAddress;
static uint16_t ledsImage;
enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1, LAST_LED = 16};

//函数声明
static uint16_t convertLedNumberToBit(int ledNumber);
static void updateHardware(void);
static bool IsLedOutOfBounds(int ledNumber);
static void setLedImageBit(int ledNumber);
static void clearLedImageBit(int ledNumber);
/**************************************************
 * @function 驱动创建和初始化函数
 *
 * @param	address 设备基地址
 *
 **************************************************/
void LedDriver_Create(uint16_t *address)
{
	ledsAddress  = address;
	//printf("ledsAddress = %p,*ledsAddress = 0x%x\n",ledsAddress,*ledsAddress);
	ledsImage    = ALL_LEDS_OFF;
	updateHardware();
}

/**************************************************
 * @function 驱动回收函数
 *
 * @param	none
 *
 **************************************************/
void LedDriver_Destroy(void)
{

}


/**************************************************
 * @function 将LED的某一位点亮
 *
 * @param	ledNumber 要打开的LED位号
 *
 **************************************************/
void LedDriver_TurnOn(int ledNumber)
{
	if(IsLedOutOfBounds(ledNumber))
		return;

	setLedImageBit(ledNumber);
	updateHardware();
}

/**************************************************
 * @function 将LED的某一位点亮
 *
 * @param	none
 *
 **************************************************/
void LedDriver_TurnAllOn()
{
	ledsImage	 = ALL_LEDS_ON;
	updateHardware();
}

/**************************************************
 * @function 查询LED的状态
 *
 * @param	ledNumber LED灯的位号
 *
 **************************************************/
bool LedDriver_IsOn(int ledNumber)
{
	if(IsLedOutOfBounds(ledNumber))
		return false;

	return (ledsImage & (convertLedNumberToBit(ledNumber)));
}

/**************************************************
 * @function 将LED的某一位关闭
 *
 * @param	ledNumber 要关闭的LED位号
 *
 **************************************************/
void LedDriver_TurnOff(int ledNumber)
{
	if(IsLedOutOfBounds(ledNumber))
		return;

	clearLedImageBit(ledNumber);
	updateHardware();
}

/**************************************************
 * @function 将LED的所有位都关闭
 *
 * @param	none
 *
 **************************************************/
void LedDriver_TurnAllOff()
{
	ledsImage	 = ALL_LEDS_OFF;
	updateHardware();
}

/**************************************************
 * @function 查询LED的状态
 *
 * @param	ledNumber LED灯的位号
 *
 **************************************************/
bool LedDriver_IsOff(int ledNumber)
{
	if(IsLedOutOfBounds(ledNumber))
		return false;

	return !LedDriver_IsOn(ledNumber);
}

/**************************************************
 * @function 将LED的某一位对应到寄存器位
 *
 * @param	ledNumber LED位号
 *
 **************************************************/
static uint16_t convertLedNumberToBit(int ledNumber)
{
	return (1 << (ledNumber - 1));
}

/**************************************************
 * @function 对LED的物理地址进行更新操作
 *
 * @param	none
 *
 **************************************************/
static void updateHardware(void)
{
	*ledsAddress = ledsImage;
}

/**************************************************
 * @function 对LED进行边界检测
 *
 * @param	ledNumber 	要操作的LED灯位号
 *
 **************************************************/
static bool IsLedOutOfBounds(int ledNumber)
{
	return ((ledNumber < FIRST_LED) || (ledNumber>LAST_LED));
}

/**************************************************
 * @function 对LED进行置位
 *
 * @param	ledNumber 	要置位的LED灯位号
 *
 **************************************************/
static void setLedImageBit(int ledNumber)
{
	ledsImage |= convertLedNumberToBit(ledNumber);
}

/**************************************************
 * @function 对LED进行清楚
 *
 * @param	ledNumber 	要清楚的LED灯位号
 *
 **************************************************/
static void clearLedImageBit(int ledNumber)
{
	ledsImage &= ~(convertLedNumberToBit(ledNumber));
}
