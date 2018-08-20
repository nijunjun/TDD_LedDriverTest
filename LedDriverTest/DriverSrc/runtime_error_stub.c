/*
 * runtime_error_stub.c
 *
 *  Created on: 2018��8��20��
 *      Author: THINK
 */

#include "runtime_error_stub.h"

//��������
static const char *message = "No Error";
static int parameter = -1;
static const char *file = 0;
static int line = -1;

//��������

/**************************************************
 * @function ������Ϣ������
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
 * @function �������µĴ�����Ϣ
 *
 * @param	none
 *
 **************************************************/
const char  *RuntimeErrorStub_GetLastError(void)
{
	return message;
}

/**************************************************
 * @function �������µĴ������
 *
 * @param	none
 *
 **************************************************/
int RuntimeErrorStub_GetLastParameter(void)
{
	return parameter;
}

/**************************************************
 * @function ���������Ϣ����ϸ���ݣ�����Ĵ������ݣ������ļ����ļ�λ��
 *
 * @param	m 	������Ϣ
 * @param   p   ����Ĳ���
 * @param   f   �ļ���
 * @param   l   �ļ�������λ��
 **************************************************/
void RuntimeError(const char *m, int p, const char *f, int l)
{
	message = m;
	parameter = p;
	file = f;
	line = l;
}
