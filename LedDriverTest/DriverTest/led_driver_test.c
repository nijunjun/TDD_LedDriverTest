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
 * @param   LedsOffAfterCreate 测试函数定义
 *
 **************************************************/
TEST(LedDriver, LedsOffAfterCreate)
{
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
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
}
