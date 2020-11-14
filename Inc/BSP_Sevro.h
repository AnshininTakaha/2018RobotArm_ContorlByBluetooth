/**
  |--------------------------------- Copyright --------------------------------|
  |                                                                            |
  |                      (C) Copyright 2019,口无，                     				 |
  |           1 Xuefu Rd, Huadu Qu, Guangzhou Shi, Guangdong Sheng, China      |
  |                           All Rights Reserved                              |
  |                                                                            |
  |           By(GCU The wold of team | 华南理工大学广州学院机器人野狼队)         |
  |                    https://github.com/GCUWildwolfteam                      |
  |----------------------------------------------------------------------------|
  |--FileName    : BSP_Sevro.h                                                
  |--Version     : v1.0                                                            
  |--Author      : 口无                                                       
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
#ifndef __BSP_SEVRO_H
#define __BSP_SEVRO_H

#include "stm32f4xx.h"
#include "stm32f4xx_hal_tim.h"
typedef struct
{
	int ArmX1;
	int ArmX2;
	int ArmX3;
	int ArmX4;
	int ArmX5;
	int ArmX6;
	int ArmX7;
	int ArmX8;
}ArmParam_t;

extern ArmParam_t ArmX;

/*通道数据解析*/
void SevroAngleSet(uint8_t *Buffer);

void SevroAngleSetXCOM(uint8_t *Buffer);

#endif
