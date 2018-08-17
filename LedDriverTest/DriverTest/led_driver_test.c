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

static uint16_t virtualLeds;

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
	LedDriver_Create(&virtualLeds);
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
 * @param   LedsOffAfterCreate ���Ժ������壬��ʼ������
 *
 **************************************************/
TEST(LedDriver, LedsOffAfterCreate)
{
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

/**************************************************
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   TurnOnLedOne ���Ժ�������,��һ��LED��
 *
 **************************************************/
TEST(LedDriver, TurnOnLedOne)
{
	LedDriver_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

/**************************************************
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   TurnOnLedOne ���Ժ�������,��һ��LED��
 *
 **************************************************/
TEST(LedDriver, TurnOnMultipleLeds)
{
	LedDriver_TurnOn(9);
	LedDriver_TurnOn(8);
	TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}


/**************************************************
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   TurnOffLedOne ���Ժ�������,�ر�һ��LED��
 *
 **************************************************/
TEST(LedDriver, TurnOffLedOne)
{
	LedDriver_TurnOff(1);
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
	RUN_TEST_CASE(LedDriver, TurnOnLedOne);
	RUN_TEST_CASE(LedDriver, TurnOffLedOne);
	RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
}
