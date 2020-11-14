/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "BSP_Sevro.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
extern uint8_t Usart6TxBuffer;
extern uint8_t Usart6RxBuffer;			//接收中断缓冲
extern uint8_t BLE4_BlueToothBuffer;
extern uint8_t Uart6_RxBuff[256];		//接收缓冲
extern uint16_t Uart6_Rx_Cnt;		//接收缓冲计数
extern uint8_t cAlmStr[];
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim5;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart6;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  HAL_RCC_NMI_IRQHandler();
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 stream5 global interrupt.
  */
void DMA1_Stream5_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream5_IRQn 0 */
	
  /* USER CODE END DMA1_Stream5_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart2_rx);
  /* USER CODE BEGIN DMA1_Stream5_IRQn 1 */

  /* USER CODE END DMA1_Stream5_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */
	
//	if(__HAL_UART_GET_FLAG(&huart2,UART_IT_IDLE) == SET)
	
	if(__HAL_UART_GET_IT_SOURCE(&huart2,UART_IT_IDLE) != RESET)
	{			
      HAL_UART_DMAStop(&huart2);
			
			HAL_UART_Receive_DMA(&huart2,(uint8_t *)&BLE4_BlueToothBuffer, 7);
			SevroAngleSet(&BLE4_BlueToothBuffer);
	}
  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */
//	__HAL_UART_CLEAR_IDLEFLAG(&huart2);
	(void)huart2.Instance->DR;
	(void)huart2.Instance->SR;
  /* USER CODE END USART2_IRQn 1 */
}

/**
  * @brief This function handles TIM5 global interrupt.
  */
void TIM5_IRQHandler(void)
{
  /* USER CODE BEGIN TIM5_IRQn 0 */

  /* USER CODE END TIM5_IRQn 0 */
  HAL_TIM_IRQHandler(&htim5);
  /* USER CODE BEGIN TIM5_IRQn 1 */

  /* USER CODE END TIM5_IRQn 1 */
}

/**
  * @brief This function handles USART6 global interrupt.
  */
void USART6_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */
		/*XCOM*/
		/*格式：X02A2500~X02A0500*/
		/*X+ID+A+角度，角度范围500~2500*/
	/*是否有中断标志出现*/
	if(__HAL_UART_GET_FLAG(&huart6,UART_FLAG_RXNE) == SET)
	{
		/*接受对应的数据并放入Usart6RxBuffer*/
		HAL_UART_Receive(&huart6,(uint8_t *)&Usart6RxBuffer, 8,0x01);
		
		/*返回Usart6RxBuffer中的数据*/
		printf("\r\nEnter:");
		HAL_UART_Transmit(&huart6,(uint8_t *)&Usart6RxBuffer,8,0x01);
		
		/*舵机数据解码*/
		SevroAngleSetXCOM(&Usart6RxBuffer);
	}		
  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart6);
  /* USER CODE BEGIN USART6_IRQn 1 */
	/*清除标志位*/
	(void)huart6.Instance->DR;
	(void)huart6.Instance->SR;
  /* USER CODE END USART6_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/*重复定义回调函数（回调函数为弱函数）*/

/*TIM回调函数*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
		/*流水灯时间*/
		static int FTIMER = 0;
	
		/*判定是进入了哪一个回调的中断*/
		/*TIM5中断*/
		if(htim->Instance == TIM5)
		{
				switch(FTIMER++ % 14)
				{
					case 0:
						HAL_GPIO_TogglePin(CustomLED_1_GPIO_Port,CustomLED_1_Pin);
						break;
					case 1:
						HAL_GPIO_TogglePin(CustomLED_2_GPIO_Port,CustomLED_2_Pin);
						break;
					case 2:
						HAL_GPIO_TogglePin(CustomLED_3_GPIO_Port,CustomLED_3_Pin);
						break;
					case 3:
						HAL_GPIO_TogglePin(CustomLED_4_GPIO_Port,CustomLED_4_Pin);
						break;
					case 4:
						HAL_GPIO_TogglePin(CustomLED_5_GPIO_Port,CustomLED_5_Pin);
						break;
					case 5:
						HAL_GPIO_TogglePin(CustomLED_6_GPIO_Port,CustomLED_6_Pin);
						break;
					case 6:
						HAL_GPIO_TogglePin(CustomLED_7_GPIO_Port,CustomLED_7_Pin);
						break;
					case 7:
						HAL_GPIO_TogglePin(CustomLED_1_GPIO_Port,CustomLED_1_Pin);
						break;
					case 8:
						HAL_GPIO_TogglePin(CustomLED_2_GPIO_Port,CustomLED_2_Pin);
						break;
					case 9:
						HAL_GPIO_TogglePin(CustomLED_3_GPIO_Port,CustomLED_3_Pin);
						break;
					case 10:
						HAL_GPIO_TogglePin(CustomLED_4_GPIO_Port,CustomLED_4_Pin);
						break;
					case 11:
						HAL_GPIO_TogglePin(CustomLED_5_GPIO_Port,CustomLED_5_Pin);
						break;
					case 12:
						HAL_GPIO_TogglePin(CustomLED_6_GPIO_Port,CustomLED_6_Pin);
						break;
					case 13:
						HAL_GPIO_TogglePin(CustomLED_7_GPIO_Port,CustomLED_7_Pin);
						break;
				}
				
				/*数据位清除*/
				if(FTIMER > 14*1000 && FTIMER % 14 == 0)
				{
						FTIMER = 0;
				}
			
				
		}
		
		
}

/*USART发送回调函数*/
//void USART6_PeriodCallBack(void)
//{
//		
//}

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//		Counter++;
//}
//void HAL_UART_RxCpltCallback(TIM_HandleTypeDef *)
//{
//		;
//}
/*串口错误中断回调函数*/
//void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
//{
//		uint8_t i = 0;
//    if(__HAL_UART_GET_FLAG(huart,UART_FLAG_ORE) != RESET) 
//    {
//        __HAL_UART_CLEAR_OREFLAG(huart);
//        HAL_UART_Receive_IT(huart,(uint8_t *)&i,1);
//    }

//}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
