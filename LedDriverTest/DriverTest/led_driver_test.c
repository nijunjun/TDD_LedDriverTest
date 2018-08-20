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
#include "runtime_error_stub.h"

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
 * @param   LedMemoryIsNotReadable ���Ժ�������,
 * 			��û��ʵ��Ӳ��ʱ���ڴ��д����ģ��
 *
 **************************************************/
TEST(LedDriver, LedMemoryIsNotReadable)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOn(8);
	TEST_ASSERT_EQUAL_HEX16(0x80, virtualLeds);
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
 * @param   TurnOnMultipleLeds ���Ժ�������,�򿪶��LED��
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
 * @param   AllOn ���Ժ�������,������LED��
 *
 **************************************************/
TEST(LedDriver, AllOn)
{
	LedDriver_TurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

/**************************************************
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   OutOfBoundsChangesNothing ���Ժ�������,���б߽����
 *
 **************************************************/
TEST(LedDriver, OutOfBoundsChangesNothing)
{
	LedDriver_TurnOn(-1);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
	LedDriver_TurnOn(0);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
	LedDriver_TurnOn(17);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
	LedDriver_TurnOn(33);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
	LedDriver_TurnOn(3141);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

/**************************************************
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   IsOn ���Ժ�������,�鿴LED�Ƶ�״̬
 *
 **************************************************/
TEST(LedDriver, IsOn)
{
	TEST_ASSERT_FALSE(LedDriver_IsOn(11));
	LedDriver_TurnOn(11);
	TEST_ASSERT_TRUE(LedDriver_IsOn(11));
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
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   TurnOffAnyLed ���Ժ�������,�ر�����һ��LED��
 *
 **************************************************/
TEST(LedDriver, TurnOffAnyLed)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOn(8);
	LedDriver_TurnOff(8);
	TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}

/**************************************************
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   TurnOffMultipleLeds ���Ժ�������,�رն��LED��
 *
 **************************************************/
TEST(LedDriver, TurnOffMultipleLeds)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(9);
	LedDriver_TurnOff(8);
	TEST_ASSERT_EQUAL_HEX16((~0x180)&0xffff, virtualLeds);
}

/**************************************************
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   AllOff ���Ժ�������,�ر�����LED��
 *
 **************************************************/
TEST(LedDriver, AllOff)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnAllOff();
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}
/**************************************************
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   OutOfBoundsTurnOffDoesNoHarm ���Ժ�������,���б߽����
 *
 **************************************************/
TEST(LedDriver, OutOfBoundsTurnOffDoesNoHarm)
{
	LedDriver_TurnAllOn();

	LedDriver_TurnOff(-1);
	LedDriver_TurnOff(0);
	LedDriver_TurnOff(17);
	LedDriver_TurnOff(33);
	LedDriver_TurnOff(3141);
	TEST_ASSERT_EQUAL_HEX16(0XFFFF, virtualLeds);
}

/**************************************************
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   OutOfBoundsProduceRuntimeError ���Ժ�������,���б߽����,�����д�����
 *
 **************************************************/
TEST(LedDriver, OutOfBoundsProduceRuntimeError)
{
	LedDriver_TurnOn(-1);
	RUNTIME_ERROR("LED Driver: out-of-bounds LED",-1);//��ӳ����ʹ���ʱ����Ϣ��ֵ

	TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED",
			RuntimeErrorStub_GetLastError());
	TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());

}

/**************************************************
 * @function TDD������
 *
 * @param	LedDriver ����
 * @param   IsOff ���Ժ�������,�鿴LED�Ƶ�״̬
 *
 **************************************************/
TEST(LedDriver, IsOff)
{
	TEST_ASSERT_TRUE(LedDriver_IsOff(11));
	LedDriver_TurnOn(11);
	TEST_ASSERT_FALSE(LedDriver_IsOff(11));
}

/**************************************************
 * @function TDD��������һ����������������и��ط��Ǵ���ģ�����Ŀǰ�������
 *
 * @param	LedDriver ����
 * @param   OutOfBoundsToDo ���Ժ�������
 *
 **************************************************/
IGNORE_TEST(LedDriver, OutOfBoundsToDo)
{
	/*TODO: what should we do during runtime?*/
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
	RUN_TEST_CASE(LedDriver, TurnOffAnyLed);
	RUN_TEST_CASE(LedDriver, LedMemoryIsNotReadable);
	RUN_TEST_CASE(LedDriver, OutOfBoundsChangesNothing);
	RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOffDoesNoHarm);
	RUN_TEST_CASE(LedDriver, OutOfBoundsProduceRuntimeError);
	RUN_TEST_CASE(LedDriver, OutOfBoundsToDo);
	RUN_TEST_CASE(LedDriver, IsOn);
	RUN_TEST_CASE(LedDriver, IsOff);
	RUN_TEST_CASE(LedDriver, TurnOffMultipleLeds);
	RUN_TEST_CASE(LedDriver, AllOn);
	RUN_TEST_CASE(LedDriver, AllOff);
}
