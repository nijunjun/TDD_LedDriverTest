/*
 * main.c
 *
 * ����ΪTDD��������
 *
 *  Created on: 2018��8��17��
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
