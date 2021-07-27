/*
 * altmain.cpp
 *
 *  Created on: Jul 23, 2021
 *      Author: user0051
 */
//#include "main.h"
#include "GPIO.hpp"
extern "C" {

int maincpp()
{
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
	GPIO_Init s = {
			GPIO::Port_C,
			{{.Pin13 = GPIO::Mode::Output}},
			{{.Pin13 = GPIO::Output_Type::Push_Pull}},
			{{.Pin13 = GPIO::Speed::Low}},
			{{.Pin13 = GPIO::Pull::No_Up_Down}},
			{{}},
			{{.Pin13 = GPIO::AlternateFunction::AF0}}
	};
#pragma GCC diagnostic pop
	GPIO &GPIOC_cpp = *new (s.Port) GPIO(s);
	while(1)
	{
		GPIOC_cpp.TogglePin(GPIO::PIN13);
		for(int i = 0; i != 168'000; ++i);
	}
}
}
