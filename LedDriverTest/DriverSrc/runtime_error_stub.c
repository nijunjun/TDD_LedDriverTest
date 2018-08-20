/*
 * runtime_error_stub.c
 *
 *  Created on: 2018年8月20日
 *      Author: THINK
 */

#include "runtime_error_stub.h"

//变量声明
static const char *message = "No Error";
static int parameter = -1;
static const char *file = 0;
static int line = -1;

//函数声明

/**************************************************
 * @function 错误信息重配置
 *
 * @param	none
 *
 **************************************************/
void RuntimeErrorStub_Reset(void)
{
	message = "No Error";
	parameter = -1;
}

/**************************************************
 * @function 返回最新的错误信息
 *
 * @param	none
 *
 **************************************************/
const char  *RuntimeErrorStub_GetLastError(void)
{
	return message;
}

/**************************************************
 * @function 返回最新的错误参数
 *
 * @param	none
 *
 **************************************************/
int RuntimeErrorStub_GetLastParameter(void)
{
	return parameter;
}

/**************************************************
 * @function 输出错误信息的详细内容，具体的错误数据，错误文件及文件位置
 *
 * @param	m 	错误信息
 * @param   p   错误的参数
 * @param   f   文件名
 * @param   l   文件所处的位置
 **************************************************/
void RuntimeError(const char *m, int p, const char *f, int l)
{
	message = m;
	parameter = p;
	file = f;
	line = l;
}
