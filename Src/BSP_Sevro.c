/**
  |--------------------------------- Copyright --------------------------------|
  |                                                                            |
  |                      (C) Copyright 2019,����,                     				 |
  |           1 Xuefu Rd, Huadu Qu, Guangzhou Shi, Guangdong Sheng, China      |
  |                           All Rights Reserved                              |
  |                                                                            |
  |           By(GCU The wold of team | ��������ѧ����ѧԺ������Ұ�Ƕ�)         |
  |                    https://github.com/GCUWildwolfteam                      |
  |----------------------------------------------------------------------------|
  |--FileName    : BSP_Sevro.c                                              
  |--Version     : v1.0                                                          
  |--Author      : ����                                                     
  |--Date        : 2019-03-22             
  |--Libsupports : 
  |--Description :                                                     
  |--FunctionList                                                     
  |-------1. ....                                                     
  |          <version>:                                                     
  |     <modify staff>:                                                       
  |             <data>:                                                       
  |      <description>:                                                        
  |-------2. ...                                                       
  |-----------------------------declaration of end-----------------------------|
 **/
#include "BSP_Sevro.h"
#include "tim.h"

ArmParam_t ArmX;

void SevroAngleSet(uint8_t *Buffer)
{
		static int AngleMotorID = 0;
		static int AngleInput = 0;
		
		/*ɨ���Ӧ����ֵ*/
		sscanf(Buffer,"X%dA%d",&AngleMotorID,&AngleInput);
		switch(AngleMotorID)
		{
			case 1:
				if(AngleInput >= 0 && AngleInput <= 180)
				{
						ArmX.ArmX1 = AngleInput;
						__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,500 + ((ArmX.ArmX1/180)*2000));
				}
				
				break;
			case 2:
				if(AngleInput >= 0 && AngleInput <= 180)
				{
						ArmX.ArmX2 = AngleInput;
						__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,500 + ((ArmX.ArmX2/180)*2000));
				}
				
				break;
			case 3:
				if(AngleInput >= 0 && AngleInput <= 180)
				{
						ArmX.ArmX3 = AngleInput;
						__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,500 + ((ArmX.ArmX3/180)*2000));
				}
				
				break;
			case 4:
				if(AngleInput >= 0 && AngleInput <= 180)
				{
						ArmX.ArmX4 = AngleInput;
						__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,500 + ((ArmX.ArmX4/180)*2000));
				}
				
				break;
			default:
				AngleMotorID = 0;
				AngleInput = 0;
				printf("��������ݲ���ȷ�������룬����������");
				break;
		}
}

void SevroAngleSetXCOM(uint8_t *Buffer)
{
		static int AngleMotorID = 0;
		static int AngleInput = 0;
	
		sscanf(Buffer,"X%dA%d",&AngleMotorID,&AngleInput);
		switch(AngleMotorID)
		{
			case 1:
				if(AngleInput >= 500 && AngleInput <= 2500)
				{
						ArmX.ArmX1 = AngleInput;
						__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,ArmX.ArmX1);
				}
				break;
			case 2:
				if(AngleInput >= 500 && AngleInput <= 2500)
				{
						ArmX.ArmX2 = AngleInput;
						__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,ArmX.ArmX2);
				}
				break;
			case 3:
				if(AngleInput >= 500 && AngleInput <= 2500)
				{
						ArmX.ArmX3 = AngleInput;
						__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,ArmX.ArmX3);
				}
				break;
			case 4:
				if(AngleInput >= 500 && AngleInput <= 2500)
				{
						ArmX.ArmX4 = AngleInput;
						__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,ArmX.ArmX4);
				}
				break;
			default:
				AngleMotorID = 0;
				AngleInput = 0;
				printf("��������ݲ���ȷ�������룬����������");
				break;
		}
}