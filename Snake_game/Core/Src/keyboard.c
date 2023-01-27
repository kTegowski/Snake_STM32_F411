/*
 * keyboard.c
 *
 *  Created on: Jan 18, 2023
 *      Author: ktego
 */
#include "main.h"
#include <stdio.h>
#include "stm32f4xx_hal.h"

void us_delay(uint32_t time,TIM_HandleTypeDef *htim ){
	HAL_TIM_Base_Start(htim);
		htim->Instance->CNT = 0;
		while (htim->Instance->CNT < time) {};
	    HAL_TIM_Base_Stop(htim);
}


