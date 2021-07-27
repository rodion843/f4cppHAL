/*
 * GPIO.cpp
 *
 *  Created on: Jul 23, 2021
 *      Author: user0051
 */

#include "GPIO.hpp"
//#include "main.h"

void* GPIO::operator new(size_t, GPIO::Port port) {
	return reinterpret_cast<void *>(0x40020000 + port * 0x400);
}

GPIO::GPIO(GPIO_Init gpio) {
	MODER.reg = gpio.Mode.reg;
	OTYPER.reg = gpio.Output_Type.reg;
	OSPEEDR.reg = gpio.Speed.reg;
	PUPDR.reg = gpio.Pull.reg;
	AFRL.reg = gpio.AlternateLow.reg;
	AFRH.reg = gpio.AlternateLow.reg;
}

GPIO::Pin GPIO::GetPin(Pin pin) const{
	return static_cast<Pin>(IDR.reg & pin);
}
void GPIO::SetPin(Pin pin){
	BSRR.str.Set = pin;
}
void GPIO::ResetPin(Pin pin){
	BSRR.str.Reset = pin;
}
void GPIO::TogglePin(Pin pin){
	if(GetPin(pin) == pin){
		ResetPin(pin);
	}else{
		SetPin(pin);
	}
}

void GPIO::TogglePort(){
	ODR.reg = IDR.reg ^ 0xffff;
}

constexpr void GPIO::StaticAssert(){

	static_assert(offsetof(GPIO, MODER) 	== 0);
	static_assert(offsetof(GPIO, OTYPER) 	== 4);
	static_assert(offsetof(GPIO, OSPEEDR) 	== 8);
	static_assert(offsetof(GPIO, PUPDR) 	== 12);
	static_assert(offsetof(GPIO, IDR) 		== 16);
	static_assert(offsetof(GPIO, ODR) 		== 20);
	static_assert(offsetof(GPIO, BSRR) 		== 24);
	static_assert(offsetof(GPIO, LCKR) 		== 28);
	static_assert(offsetof(GPIO, AFRL) 		== 32);
	static_assert(offsetof(GPIO, AFRH) 		== 36);

	static_assert(sizeof(GPIO_Init::Port) 			== 1, "GPIO_Init::Port must be 1 bytes in size");
	static_assert(sizeof(GPIO_Init::Mode) 			== 4, "GPIO_Init::Mode must be 4 bytes in size");
	static_assert(sizeof(GPIO_Init::Output_Type) 	== 2, "GPIO_Init::Output_Type must be 2 bytes in size");
	static_assert(sizeof(GPIO_Init::Speed) 			== 4, "GPIO_Init::Speed must be 4 bytes in size");
	static_assert(sizeof(GPIO_Init::Pull) 			== 4, "GPIO_Init::Pull must be 4 bytes in size");
	static_assert(sizeof(GPIO_Init::AlternateLow)	== 4, "GPIO_Init::Alternate must be 4 bytes in size");
	static_assert(sizeof(GPIO_Init::AlternateHigh)	== 4, "GPIO_Init::Alternate must be 4 bytes in size");

	static_assert(sizeof(Device_Register) 			== 4, "Device_Register must be 4 bytes in size");
	static_assert(alignof(Device_Register) 			== 4, "Device_Register must be word‐aligned");
	static_assert(sizeof(GPIO::Pin) 				== 2, "GPIO::Pin must be 2 bytes in size");

	static_assert(std::is_unsigned<Device_Register>::value, "Device_Register must be unsigned");
	static_assert(sizeof(GPIO) == (10 * sizeof(Device_Register)), "Padding at GPIO class");
	static_assert(std::is_standard_layout<GPIO>::value,   "GPIO must be standart layout");

}
