/*
 * led_driver_test.c
 *
 * �������ڴ���TDD���Եľ�������
 *
 *  Created on: 2018��8��17��
 *      Author: NJ
 */

#include "unity_fixture.h"
#include "led_status_ctrl.h"

/**************************************************
 * @function TDD����������
 *
 * @param	LedDriver ����
 *
 **************************************************/
TEST_GROUP(LedDriver);

/**************************************************
 * @function TDD���Դ�������
 *
 * @param	LedDriver ����
 *
 **************************************************/
TEST_SETUP(LedDriver)
{
}

/**************************************************
 * @function TDD���Խ�������
 *
 * @param	LedDriver ����
 *
 **************************************************/
TEST_TEAR_DOWN(LedDriver)
{
}

/**************************************************
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   LedsOffAfterCreate ���Ժ�������
 *
 **************************************************/
TEST(LedDriver, LedsOffAfterCreate)
{
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

/**************************************************
 * @function TDD���������������
 *
 * @param	LedDriver ����
 *
 **************************************************/
TEST_GROUP_RUNNER(LedDriver)
{
	RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
}
