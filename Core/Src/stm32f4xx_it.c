/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "global_vars.h"
#include "control_code.h"
#include "fonts.h"
#include "i2c.h"
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
static uint16_t global_gpio_pin = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim6;
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
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
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
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */

  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(BTN_Pin);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}

/**
  * @brief This function handles TIM6 global interrupt and DAC1, DAC2 underrun error interrupts.
  */
void TIM6_DAC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_DAC_IRQn 0 */

  /* USER CODE END TIM6_DAC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */

  /* USER CODE END TIM6_DAC_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	global_gpio_pin = GPIO_Pin;
	__HAL_TIM_CLEAR_IT(&htim6, TIM_IT_UPDATE);
	HAL_TIM_Base_Start_IT(&htim6);

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	static uint8_t state = 0;
	static int count = 0;
	static uint8_t BTN_Trigger = 0;
	static char timerBuffer[20];

	if (htim->Instance == TIM6){
		if (HAL_GPIO_ReadPin(BTN_GPIO_Port, global_gpio_pin) == GPIO_PIN_RESET){
			if (global_gpio_pin == BTN_Pin){
				BTN_Trigger = 1;
			}
		}
		HAL_TIM_Base_Stop_IT(&htim6);
	}

	if (htim->Instance == TIM2) {
		count++;
		// Car Semaphore Cycle
		switch (state) {
			case 0:
				if ((count >= GRN_Period) && (BTN_Trigger == 1)) {  // Green light turns off after GRN_Period (default 15)
					HAL_GPIO_WritePin(GPIOB, C_GRN_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, C_YLW_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB, C_RED_Pin, GPIO_PIN_RESET);
					count = 0;
					state = 1;
					BTN_Trigger = 0;
				}
				if((GRN_Period-count) <= 3 && (BTN_Trigger == 1)){
					HAL_GPIO_TogglePin(GPIOB, C_GRN_Pin);
				}
				break;
			case 1:
				if (count >= YLW_Period) {  // Yellow light turns off after YLW_Period (default 3)
					HAL_GPIO_WritePin(GPIOB, C_GRN_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, C_YLW_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, C_RED_Pin, GPIO_PIN_SET);
					count = 0;
					state = 2;
				}
				break;
			case 2:
				screenClear();
				screenSetCursor(64,32);
				sprintf(timerBuffer, "%d", (RED_Period-count));
				screenWriteStr(timerBuffer, Font_7x10);
				screenUpdate(&hi2c1);
				if ((RED_Period-count) <= 5) {
					HAL_GPIO_TogglePin(GPIOA, P_GRN_Pin);
				}
				if ((RED_Period-count) < 2){
					HAL_GPIO_WritePin(GPIOA, P_GRN_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, P_RED_Pin, GPIO_PIN_SET);
				}
				if (count >= RED_Period) {  // Red light turns off after RED_Period (default 10)
					HAL_GPIO_WritePin(GPIOB, C_GRN_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB, C_YLW_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, C_RED_Pin, GPIO_PIN_RESET);
					count = 0;
					state = 0;
				}
				if (count == 1){
					HAL_GPIO_WritePin(GPIOA, P_GRN_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, P_RED_Pin, GPIO_PIN_RESET);
				}
				break;
		}
	}
}
/* USER CODE END 1 */
