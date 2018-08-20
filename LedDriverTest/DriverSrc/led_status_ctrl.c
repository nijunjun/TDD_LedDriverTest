/*
 * led_status_ctrl.c
 * �������ڶ�LED�������ƽ��о���ʵ�֣����ڡ�����������Ƕ��ʽC���Կ�������3�½������
 *
 *  Created on: 2018��8��17��
 *      Author: NJ
 */

#include "led_status_ctrl.h"

//�궨������

//��������
static uint16_t *ledsAddress;
static uint16_t ledsImage;
enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1, LAST_LED = 16};

//��������
static uint16_t convertLedNumberToBit(int ledNumber);
static void updateHardware(void);
static bool IsLedOutOfBounds(int ledNumber);
static void setLedImageBit(int ledNumber);
static void clearLedImageBit(int ledNumber);
/**************************************************
 * @function ���������ͳ�ʼ������
 *
 * @param	address �豸����ַ
 *
 **************************************************/
void LedDriver_Create(uint16_t *address)
{
	ledsAddress  = address;
	//printf("ledsAddress = %p,*ledsAddress = 0x%x\n",ledsAddress,*ledsAddress);
	ledsImage    = ALL_LEDS_OFF;
	updateHardware();
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
 * @param	ledNumber Ҫ�򿪵�LEDλ��
 *
 **************************************************/
void LedDriver_TurnOn(int ledNumber)
{
	if(IsLedOutOfBounds(ledNumber))
		return;

	setLedImageBit(ledNumber);
	updateHardware();
}

/**************************************************
 * @function ��LED��ĳһλ����
 *
 * @param	none
 *
 **************************************************/
void LedDriver_TurnAllOn()
{
	ledsImage	 = ALL_LEDS_ON;
	updateHardware();
}

/**************************************************
 * @function ��ѯLED��״̬
 *
 * @param	ledNumber LED�Ƶ�λ��
 *
 **************************************************/
bool LedDriver_IsOn(int ledNumber)
{
	if(IsLedOutOfBounds(ledNumber))
		return false;

	return (ledsImage & (convertLedNumberToBit(ledNumber)));
}

/**************************************************
 * @function ��LED��ĳһλ�ر�
 *
 * @param	ledNumber Ҫ�رյ�LEDλ��
 *
 **************************************************/
void LedDriver_TurnOff(int ledNumber)
{
	if(IsLedOutOfBounds(ledNumber))
		return;

	clearLedImageBit(ledNumber);
	updateHardware();
}

/**************************************************
 * @function ��LED������λ���ر�
 *
 * @param	none
 *
 **************************************************/
void LedDriver_TurnAllOff()
{
	ledsImage	 = ALL_LEDS_OFF;
	updateHardware();
}

/**************************************************
 * @function ��ѯLED��״̬
 *
 * @param	ledNumber LED�Ƶ�λ��
 *
 **************************************************/
bool LedDriver_IsOff(int ledNumber)
{
	if(IsLedOutOfBounds(ledNumber))
		return false;

	return !LedDriver_IsOn(ledNumber);
}

/**************************************************
 * @function ��LED��ĳһλ��Ӧ���Ĵ���λ
 *
 * @param	ledNumber LEDλ��
 *
 **************************************************/
static uint16_t convertLedNumberToBit(int ledNumber)
{
	return (1 << (ledNumber - 1));
}

/**************************************************
 * @function ��LED�������ַ���и��²���
 *
 * @param	none
 *
 **************************************************/
static void updateHardware(void)
{
	*ledsAddress = ledsImage;
}

/**************************************************
 * @function ��LED���б߽���
 *
 * @param	ledNumber 	Ҫ������LED��λ��
 *
 **************************************************/
static bool IsLedOutOfBounds(int ledNumber)
{
	return ((ledNumber < FIRST_LED) || (ledNumber>LAST_LED));
}

/**************************************************
 * @function ��LED������λ
 *
 * @param	ledNumber 	Ҫ��λ��LED��λ��
 *
 **************************************************/
static void setLedImageBit(int ledNumber)
{
	ledsImage |= convertLedNumberToBit(ledNumber);
}

/**************************************************
 * @function ��LED�������
 *
 * @param	ledNumber 	Ҫ�����LED��λ��
 *
 **************************************************/
static void clearLedImageBit(int ledNumber)
{
	ledsImage &= ~(convertLedNumberToBit(ledNumber));
}
