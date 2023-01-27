/*
 * readGesture.c
 *
 *  Created on: Jan 4, 2023
 *      Author: ktego
 */
#include <stdio.h>
#include "main.h"
#include "snake.h"

uint8_t up = 0;
uint8_t down = 0;
uint8_t left = 0;
uint8_t right = 0;
uint8_t oldstate[4];
uint8_t newstate[4];

void initGesture(I2C_HandleTypeDef * i2c){
	uint8_t test1 = 0x1;
	uint8_t test = test1 | test1 << 6| test1<<2;
	uint8_t test2 = test | test1 << 7;
	uint8_t test3 = test1<<4 | test1 << 5;
	uint8_t test4 = test1<<7 | test1 << 6;



	if(HAL_I2C_Mem_Write(i2c, 0x39<<1, 0x80, 1, &test1, 1, 100) == HAL_ERROR){
	    	  while(1){

	    	  }
	      }
	    HAL_Delay(100);
	    if(HAL_I2C_Mem_Write(i2c, 0x39<<1, 0x80, 1, &test, 1, 100) == HAL_ERROR){

	       }
	    HAL_Delay(100);
	    if(HAL_I2C_Mem_Write(i2c, 0x39<<1, 0x80, 1, &test, 1, 100) == HAL_ERROR){

	       }
	    HAL_Delay(100);

	    if(HAL_I2C_Mem_Write(i2c, 0x39<<1,0xAB, 1, &test1, 1, 100) == HAL_ERROR){

	           }
//	    HAL_Delay(100);
//	    if(HAL_I2C_Mem_Write(i2c, 0x39<<1,0xA4, 1, &test2, 1, 100) == HAL_ERROR){
//
//	               }
//	    if(HAL_I2C_Mem_Write(i2c, 0x39<<1,0xA5, 1, &test2, 1, 100) == HAL_ERROR){
//
//	                  }
//	    if(HAL_I2C_Mem_Write(i2c, 0x39<<1,0xA7, 1, &test2, 1, 100) == HAL_ERROR){
//
//	                  }
//	    if(HAL_I2C_Mem_Write(i2c, 0x39<<1,0xA9, 1, &test2, 1, 100) == HAL_ERROR){
//
//	                  }
//
//	    if(HAL_I2C_Mem_Write(i2c, 0x39<<1,0x90, 1, &test3, 1, 100) == HAL_ERROR){
//
//	                     }
//
//	    if(HAL_I2C_Mem_Write(i2c, 0x39<<1,0xA2, 1, &test4, 1, 100) == HAL_ERROR){
//
//	                         }
}
void readGesture(I2C_HandleTypeDef * i2c){
	if(HAL_I2C_Mem_Read(i2c, 0x39<<1, 0xFC, 1, &up, 1, 100) == HAL_ERROR){
		  	  }
		  	  HAL_Delay(10);
		  if(HAL_I2C_Mem_Read(i2c, 0x39<<1, 0xFD, 1, &down, 1, 100) == HAL_ERROR){
		 	}
		  	  HAL_Delay(10);
	      if(HAL_I2C_Mem_Read(i2c, 0x39<<1, 0xFE, 1, &left, 1, 100) == HAL_ERROR){
		  	}
		 	  HAL_Delay(10);
		  if(HAL_I2C_Mem_Read(i2c, 0x39<<1, 0xFF, 1, &right, 1, 100) == HAL_ERROR){
		    }
		      HAL_Delay(10);
		   *oldstate = *newstate;
		   newstate[0] = up;
		   newstate[1] = down;
		   newstate[2] = left;
		   newstate[3] = right;
}

int decodeGesture(int destinationFlag){

	if(up - oldstate[1] > 100){
		return 0;
	}
	if(down - oldstate[0] > 100){
		return 3;
	}
	if(left - oldstate[3] > 100){
			return 1;		}
	if(right - oldstate[2] > 100){
			return 2;
		}
	return destinationFlag;
}
