/*
 * main.c
 *
 * 本文为TDD的主函数，基于《测试驱动的嵌入式C语言开发》第3章进行
 *
 *  Created on: 2018年8月17日
 *      Author: NJ
 */

#include "unity_fixture.h"

static void RunAllTests(void)
{
	RUN_TEST_GROUP(LedDriver);
}

int main(int argc, char *argv[])
{
	return UnityMain(argc, argv, RunAllTests);
}
