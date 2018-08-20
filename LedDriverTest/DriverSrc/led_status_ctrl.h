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
#include <stdbool.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_Destroy(void);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnAllOn();
bool LedDriver_IsOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOff();
bool LedDriver_IsOff(int ledNumber);
#endif /* DRIVERSRC_LED_STATUS_CTRL_H_ */
