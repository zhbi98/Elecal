#ifndef __INA226_H__
#define __INA226_H__

#include "ina226_i2c.h"


#define MODE_INA226 0X4327//0x4127

#define 	CFG_REG	 		0X00		//
#define 	SV_REG 			0X01		//������ѹ
#define 	BV_REG 			0X02		//���ߵ�ѹ
#define 	PWR_REG 		0X03		//��Դ����
#define 	CUR_REG 		0X04		//����
#define 	CAL_REG 		0X05		//У׼���趨�����̷�Χ�Լ������͹��ʲ����� 
#define 	ONFF_REG 		0X06		//���� ʹ�� �������ú�ת��׼������
#define 	AL_REG 			0X07		//��������ѡ����������Ƚϵ��޶�ֵ
#define 	INA226_GET_ADDR 0XFF//0x2260		//����Ψһ��оƬ��ʶ��
#define   	INA226_ADDR1	0x80
#define     INA226_GETALADDR	0X14

//������������
#define 	INA226_VAL_LSB	2.5f	//������ѹ LSB 2.5uV
#define     Voltage_LSB		1.25f   //���ߵ�ѹ LSB 1.25mV
#define     CURRENT_LSB 	1.0f 	//����LSB 1mA
#define     POWER_LSB       25*CURRENT_LSB
#define     CAL             1024     //0.00512/(Current_LSB*R_SHUNT) = 512  //����ƫ���С

typedef struct
{
    float voltageVal;			//mV
    float Shunt_voltage;		//uV
    float Shunt_Current;		//mA
    float Power_Val;			//����
    float Power;				//����mW
    uint32_t   ina226_id;
} INA226;

void INA226_SetRegPointer(uint8_t addr,uint8_t reg);
void INA226_SendData(uint8_t addr,uint8_t reg,uint16_t data);
uint16_t INA226_ReadData(uint8_t addr);

void     INA226_Get_ID(uint8_t addr);			//��ȡ id
uint16_t INA226_GET_CAL_REG(uint8_t addr);		//��ȡУ׼ֵ
uint16_t INA226_GetVoltage( uint8_t addr);		//��ȡ���ߵ�ѹװ��ֵ
int16_t INA226_GetShunt_Current(uint8_t addr);	//��ȡ��������װ��ֵ
int16_t INA226_GetShuntVoltage(uint8_t addr);	//������ѹװ��ֵ
uint16_t INA226_Get_Power(uint8_t addr);		//��ȡ����װ��ֵ����ʹ��

void INA226_Init(void);
void GetVoltage(float *Voltage);
void Get_Shunt_voltage(float *Current);
void Get_Shunt_Current(float *Current);
void get_power(void);						////��ȡ����= ���ߵ�ѹ * ����

uint8_t	INA226_AlertAddr(void);
void Get_Power(float *Power);

extern INA226 ina226_data;
#endif

