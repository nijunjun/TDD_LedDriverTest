/*
 * led_status_ctrl.h
 *
 * �������ڶ�LED״̬�������Ƶĺ�����������
 *
 *  Created on: 2018��8��17��
 *      Author: NJ
 */

#ifndef DRIVERSRC_LED_STATUS_CTRL_H_
#define DRIVERSRC_LED_STATUS_CTRL_H_

#include <stdint.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_Destroy(void);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);

#endif /* DRIVERSRC_LED_STATUS_CTRL_H_ */
