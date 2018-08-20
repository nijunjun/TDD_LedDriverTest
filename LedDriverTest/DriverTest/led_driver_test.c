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
#include "runtime_error_stub.h"

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
 * @param   LedMemoryIsNotReadable 测试函数定义,
 * 			对没有实际硬件时的内存读写进行模拟
 *
 **************************************************/
TEST(LedDriver, LedMemoryIsNotReadable)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOn(8);
	TEST_ASSERT_EQUAL_HEX16(0x80, virtualLeds);
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
 * @param   TurnOnMultipleLeds 测试函数定义,打开多个LED灯
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
 * @param   AllOn 测试函数定义,打开所有LED灯
 *
 **************************************************/
TEST(LedDriver, AllOn)
{
	LedDriver_TurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

/**************************************************
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   OutOfBoundsChangesNothing 测试函数定义,进行边界测试
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
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   IsOn 测试函数定义,查看LED灯的状态
 *
 **************************************************/
TEST(LedDriver, IsOn)
{
	TEST_ASSERT_FALSE(LedDriver_IsOn(11));
	LedDriver_TurnOn(11);
	TEST_ASSERT_TRUE(LedDriver_IsOn(11));
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
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   TurnOffAnyLed 测试函数定义,关闭任意一个LED灯
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
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   TurnOffMultipleLeds 测试函数定义,关闭多个LED灯
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
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   AllOff 测试函数定义,关闭所有LED灯
 *
 **************************************************/
TEST(LedDriver, AllOff)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnAllOff();
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}
/**************************************************
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   OutOfBoundsTurnOffDoesNoHarm 测试函数定义,进行边界测试
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
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   OutOfBoundsProduceRuntimeError 测试函数定义,进行边界测试,并进行错误检测
 *
 **************************************************/
TEST(LedDriver, OutOfBoundsProduceRuntimeError)
{
	LedDriver_TurnOn(-1);
	RUNTIME_ERROR("LED Driver: out-of-bounds LED",-1);//添加程序发送错误时的信息赋值

	TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED",
			RuntimeErrorStub_GetLastError());
	TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());

}

/**************************************************
 * @function TDD测试项
 *
 * @param	LedDriver 组名
 * @param   IsOff 测试函数定义,查看LED灯的状态
 *
 **************************************************/
TEST(LedDriver, IsOff)
{
	TEST_ASSERT_TRUE(LedDriver_IsOff(11));
	LedDriver_TurnOn(11);
	TEST_ASSERT_FALSE(LedDriver_IsOff(11));
}

/**************************************************
 * @function TDD测试项，添加一个忽略项，用于提醒有个地方是待测的，但是目前将其忽略
 *
 * @param	LedDriver 组名
 * @param   OutOfBoundsToDo 测试函数定义
 *
 **************************************************/
IGNORE_TEST(LedDriver, OutOfBoundsToDo)
{
	/*TODO: what should we do during runtime?*/
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
