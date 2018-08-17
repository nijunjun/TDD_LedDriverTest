/*
 * main.c
 *
 * 本文为TDD的主函数
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
