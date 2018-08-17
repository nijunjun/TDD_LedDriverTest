/*
 * led_status_ctrl.c
 * 本文用于对LED驱动控制进行具体实现，基于《测试驱动的嵌入式C语言开发》第3章进行设计
 *
 *  Created on: 2018年8月17日
 *      Author: NJ
 */

#include "led_status_ctrl.h"

static uint16_t *ledAddress;

/**************************************************
 * @function 驱动创建和初始化函数
 *
 * @param	address 设备基地址
 *
 **************************************************/
void LedDriver_Create(uint16_t *address)
{
	ledAddress  = address;
	*ledAddress = 0;
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
 * @param	address 设备基地址
 *
 **************************************************/
void LedDriver_TurnOn(int ledNumber)
{
	*ledAddress |= (1 << (ledNumber - 1));
}

/**************************************************
 * @function 将LED的某一位关闭
 *
 * @param	address 设备基地址
 *
 **************************************************/
void LedDriver_TurnOff(int ledNumber)
{
	*ledAddress = 0;
}
