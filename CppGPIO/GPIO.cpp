/*
 * GPIO.cpp
 *
 *  Created on: Jul 23, 2021
 *      Author: user0051
 */

#include "GPIO.hpp"
#include "main.h"

void* GPIO::operator new(size_t, GPIO_Init gpio) {
	return nullptr;//reinterpret_cast<void *>(0x40020000 + port * 0x400);
}

GPIO::GPIO() {
	// TODO Auto-generated constructor stub

}

GPIO::Pin GPIO::GetPin(Pin pin) const{
	return static_cast<Pin>(IDR & pin);
}
void GPIO::SetPin(Pin pin){
	BSRRs.Set = pin;
}
void GPIO::ResetPin(Pin pin){
	BSRRs.Reset = pin;
}
void GPIO::TogglePin(Pin pin){
	if(GetPin(pin) == pin){
		ResetPin(pin);
	}else{
		SetPin(pin);
	}
}

void GPIO::TogglePort(){
	ODR = IDR ^ 0xffff;
}
