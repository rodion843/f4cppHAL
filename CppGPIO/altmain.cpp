/*
 * altmain.cpp
 *
 *  Created on: Jul 23, 2021
 *      Author: user0051
 */
#include "main.h"
#include "GPIO.hpp"
extern "C" {
//GPIO *GPIOA_cpp = new (GPIO::A) GPIO;


int maincpp(){
	GPIO_Init s{};
	GPIO &GPIOC_cpp = *new (s) GPIO;
	while(1){
	  GPIOC_cpp.TogglePin(GPIO::PIN13);
	  HAL_Delay(250);
	}
}
}
