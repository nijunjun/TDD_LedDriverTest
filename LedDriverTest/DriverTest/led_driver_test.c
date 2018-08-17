/*
 * led_driver_test.c
 *
 * 本文用于创建TDD测试的具体需求
 *
 *  Created on: 2018年8月17日
 *      Author: NJ
 */

#include "unity_fixture.h"
#include "led_status_ctrl.h"

static uint16_t virtualLeds;

/**************************************************
 * @function TDD测试组声明
 *
 * @param	LedDriver 组名
 *
 **************************************************/
TEST_GROUP(LedDriver);

/**************************************************
 * @function TDD测试创建声明
 *
 * @param	LedDriver 组名
 *
 **************************************************/
TEST_SETUP(LedDriver)
{
	LedDriver_Create(&virtualLeds);
}

/**************************************************
 * @function TDD测试结束声明
 *
 * @param	LedDriver 组名
 *
 **************************************************/
TEST_TEAR_DOWN(LedDriver)
{
}

/**************************************************
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   LedsOffAfterCreate 测试函数定义，初始化驱动
 *
 **************************************************/
TEST(LedDriver, LedsOffAfterCreate)
{
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

/**************************************************
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   TurnOnLedOne 测试函数定义,打开一个LED灯
 *
 **************************************************/
TEST(LedDriver, TurnOnLedOne)
{
	LedDriver_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

/**************************************************
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   TurnOnLedOne 测试函数定义,打开一个LED灯
 *
 **************************************************/
TEST(LedDriver, TurnOnMultipleLeds)
{
	LedDriver_TurnOn(9);
	LedDriver_TurnOn(8);
	TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}


/**************************************************
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   TurnOffLedOne 测试函数定义,关闭一个LED灯
 *
 **************************************************/
TEST(LedDriver, TurnOffLedOne)
{
	LedDriver_TurnOff(1);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

/**************************************************
 * @function TDD测试项的所有内容
 *
 * @param	LedDriver 组名
 *
 **************************************************/
TEST_GROUP_RUNNER(LedDriver)
{
	RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
	RUN_TEST_CASE(LedDriver, TurnOnLedOne);
	RUN_TEST_CASE(LedDriver, TurnOffLedOne);
	RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
}
