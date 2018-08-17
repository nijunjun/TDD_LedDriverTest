/*
 * led_status_ctrl.c
 * �������ڶ�LED�������ƽ��о���ʵ�֣����ڡ�����������Ƕ��ʽC���Կ�������3�½������
 *
 *  Created on: 2018��8��17��
 *      Author: NJ
 */

#include "led_status_ctrl.h"

static uint16_t *ledAddress;

/**************************************************
 * @function ���������ͳ�ʼ������
 *
 * @param	address �豸����ַ
 *
 **************************************************/
void LedDriver_Create(uint16_t *address)
{
	ledAddress  = address;
	*ledAddress = 0;
}

/**************************************************
 * @function �������պ���
 *
 * @param	none
 *
 **************************************************/
void LedDriver_Destroy(void)
{

}

/**************************************************
 * @function ��LED��ĳһλ����
 *
 * @param	address �豸����ַ
 *
 **************************************************/
void LedDriver_TurnOn(int ledNumber)
{
	*ledAddress |= (1 << (ledNumber - 1));
}

/**************************************************
 * @function ��LED��ĳһλ�ر�
 *
 * @param	address �豸����ַ
 *
 **************************************************/
void LedDriver_TurnOff(int ledNumber)
{
	*ledAddress = 0;
}
