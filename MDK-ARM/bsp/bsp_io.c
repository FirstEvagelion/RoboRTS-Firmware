/****************************************************************************
 *  Copyright (C) 2018 RoboMaster.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/
/** @file bsp_io.c
 *  @version 1.0
 *  @date June 2017
 *
 *  @brief basic IO port operation
 *
 *  @copyright 2017 DJI RoboMaster. All rights reserved.
 *
 */

#include "bsp_io.h"
#include "sys_config.h"
#include "tim.h"

void turn_on_laser(void)
{
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
}

void turn_off_laser(void)
{
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
}

uint8_t get_bbkey_state(void)
{
<<<<<<< HEAD
<<<<<<< HEAD
	
  return HAL_GPIO_ReadPin(TRIG_GPIO_Port, TRIG_Pin);
=======
  static uint32_t last_change_time = 0;
  static uint8_t last_state = 0;
  uint8_t state = HAL_GPIO_ReadPin(TRIG_GPIO_Port, TRIG_Pin);
  if(state == last_state){
    last_change_time = HAL_GetTick();
  } else {
    if(HAL_GetTick()-last_change_time >= 3){
      //change keep 3ms
      //the purpose is to remove the jitter of key
      last_state = state;
    }
  }
  return last_state; //changed by Mr.bin 20180421
>>>>>>> dev-bin
=======
  //changed by Mr.bin 20180430
  return HAL_GPIO_ReadPin(TRIG_GPIO_Port, TRIG_Pin);
>>>>>>> origin/dev-bin
}


void turn_on_friction_wheel(uint16_t spd)
{
  LEFT_FRICTION  = spd;
  RIGHT_FIRCTION = spd;
}

void turn_off_friction_wheel(void)
{
  LEFT_FRICTION  = 1000;
  RIGHT_FIRCTION = 1000;
}

void mpu_heat_ctrl(uint16_t pwm_pulse)
{
  IMU_PWM_PULSE = pwm_pulse;
}

void pwm_device_init(void)
{
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); // ctrl imu temperature
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1); // beep
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1); // friction wheel
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}

uint8_t sd_insert(void)
{
  return !HAL_GPIO_ReadPin(SD_EXTI_GPIO_Port, SD_EXTI_Pin);
}
