/*
 * GPIO.hpp
 *
 *  Created on: Jul 23, 2021
 *      Author: user0051
 */

#ifndef CPPGPIO_GPIO_HPP_
#define CPPGPIO_GPIO_HPP_

#include <cstdint>
#include <cstddef>
#include <type_traits>
using Device_Register = volatile uint32_t;
struct GPIO_Init;
class GPIO {
public:
	enum Port {A, B, C, D, E, F, G, I};
	enum Pin : uint16_t {
		PIN0 = 1 << 0,
		PIN1 = 1 << 1,
		PIN2 = 1 << 2,
		PIN3 = 1 << 3,
		PIN4 = 1 << 4,
		PIN5 = 1 << 5,
		PIN6 = 1 << 6,
		PIN7 = 1 << 7,
		PIN8 = 1 << 8,
		PIN9 = 1 << 9,
		PIN10 = 1 << 10,
		PIN11 = 1 << 11,
		PIN12 = 1 << 12,
		PIN13 = 1 << 13,
		PIN14 = 1 << 14,
		PIN15 = 1 << 15,
	};
	enum Mode {
		Input = 0,
		Output = 1,
		AltFunc = 2,
		Analog = 3
	};
	enum Pull{
		No_Up_Down,
		Pull_Up,
		Pull_Down
	};
	enum Output_Type {
		Push_Pull = 0,
		Open_Drain = 1
	};
	enum Speed{
		Low = 0,
		Medium = 1,
		High = 2,
		Very_High = 3
	};
	GPIO();
	void *operator new(size_t, GPIO_Init gpio);
	void TogglePin(Pin pin);
	Pin GetPin(Pin pin) const;
	void SetPin(Pin pin);
	void ResetPin(Pin pin);
	void TogglePort();
private:
	union {
		Device_Register MODER : 32;
		struct{
			Device_Register PIN_0 : 2;
			Device_Register PIN_1 : 2;
			Device_Register PIN_2 : 2;
			Device_Register PIN_3 : 2;
			Device_Register PIN_4 : 2;
			Device_Register PIN_5 : 2;
			Device_Register PIN_6 : 2;
			Device_Register PIN_7 : 2;
			Device_Register PIN_8 : 2;
			Device_Register PIN_9 : 2;
			Device_Register PIN_10 : 2;
			Device_Register PIN_11 : 2;
			Device_Register PIN_12 : 2;
			Device_Register PIN_13 : 2;
			Device_Register PIN_14 : 2;
			Device_Register PIN_15 : 2;
		}MODERs;
	};
	union {
		Device_Register OTYPER : 16;
		struct{
			Device_Register PIN_0 : 1;
			Device_Register PIN_1 : 1;
			Device_Register PIN_2 : 1;
			Device_Register PIN_3 : 1;
			Device_Register PIN_4 : 1;
			Device_Register PIN_5 : 1;
			Device_Register PIN_6 : 1;
			Device_Register PIN_7 : 1;
			Device_Register PIN_8 : 1;
			Device_Register PIN_9 : 1;
			Device_Register PIN_10 : 1;
			Device_Register PIN_11 : 1;
			Device_Register PIN_12 : 1;
			Device_Register PIN_13 : 1;
			Device_Register PIN_14 : 1;
			Device_Register PIN_15 : 1;
		}OTYPERs;
	};
	union {
		Device_Register OSPEEDR : 32;
		struct{
			Device_Register PIN_0 : 2;
			Device_Register PIN_1 : 2;
			Device_Register PIN_2 : 2;
			Device_Register PIN_3 : 2;
			Device_Register PIN_4 : 2;
			Device_Register PIN_5 : 2;
			Device_Register PIN_6 : 2;
			Device_Register PIN_7 : 2;
			Device_Register PIN_8 : 2;
			Device_Register PIN_9 : 2;
			Device_Register PIN_10 : 2;
			Device_Register PIN_11 : 2;
			Device_Register PIN_12 : 2;
			Device_Register PIN_13 : 2;
			Device_Register PIN_14 : 2;
			Device_Register PIN_15 : 2;
		}OSPEEDRs;
	};
	union {
		Device_Register PUPDR : 32;
		struct{
			Device_Register PIN_0 : 2;
			Device_Register PIN_1 : 2;
			Device_Register PIN_2 : 2;
			Device_Register PIN_3 : 2;
			Device_Register PIN_4 : 2;
			Device_Register PIN_5 : 2;
			Device_Register PIN_6 : 2;
			Device_Register PIN_7 : 2;
			Device_Register PIN_8 : 2;
			Device_Register PIN_9 : 2;
			Device_Register PIN_10 : 2;
			Device_Register PIN_11 : 2;
			Device_Register PIN_12 : 2;
			Device_Register PIN_13 : 2;
			Device_Register PIN_14 : 2;
			Device_Register PIN_15 : 2;
		}PUPDRs;
	};
	union {
		Device_Register IDR : 16;
		struct{
			Device_Register PIN_0 : 1;
			Device_Register PIN_1 : 1;
			Device_Register PIN_2 : 1;
			Device_Register PIN_3 : 1;
			Device_Register PIN_4 : 1;
			Device_Register PIN_5 : 1;
			Device_Register PIN_6 : 1;
			Device_Register PIN_7 : 1;
			Device_Register PIN_8 : 1;
			Device_Register PIN_9 : 1;
			Device_Register PIN_10 : 1;
			Device_Register PIN_11 : 1;
			Device_Register PIN_12 : 1;
			Device_Register PIN_13 : 1;
			Device_Register PIN_14 : 1;
			Device_Register PIN_15 : 1;
		}IDRs;
	};
	union {
		Device_Register ODR : 16;
		struct{
			Device_Register PIN_0 : 1;
			Device_Register PIN_1 : 1;
			Device_Register PIN_2 : 1;
			Device_Register PIN_3 : 1;
			Device_Register PIN_4 : 1;
			Device_Register PIN_5 : 1;
			Device_Register PIN_6 : 1;
			Device_Register PIN_7 : 1;
			Device_Register PIN_8 : 1;
			Device_Register PIN_9 : 1;
			Device_Register PIN_10 : 1;
			Device_Register PIN_11 : 1;
			Device_Register PIN_12 : 1;
			Device_Register PIN_13 : 1;
			Device_Register PIN_14 : 1;
			Device_Register PIN_15 : 1;
		}ODRs;
	};
	union {
		Device_Register BSRR : 32;
		struct{
			Device_Register Set : 16;
			Device_Register Reset : 16;
		}BSRRs;
	};
	union {
		Device_Register LCKR : 17;
		struct{
			Device_Register PIN_0 : 1;
			Device_Register PIN_1 : 1;
			Device_Register PIN_2 : 1;
			Device_Register PIN_3 : 1;
			Device_Register PIN_4 : 1;
			Device_Register PIN_5 : 1;
			Device_Register PIN_6 : 1;
			Device_Register PIN_7 : 1;
			Device_Register PIN_8 : 1;
			Device_Register PIN_9 : 1;
			Device_Register PIN_10 : 1;
			Device_Register PIN_11 : 1;
			Device_Register PIN_12 : 1;
			Device_Register PIN_13 : 1;
			Device_Register PIN_14 : 1;
			Device_Register PIN_15 : 1;
			Device_Register LCKK : 1;
		}LCKRs;
	};
	union {
		Device_Register AFRL : 32;
		struct{
			Device_Register AFR0 : 4;
			Device_Register AFR1 : 4;
			Device_Register AFR2 : 4;
			Device_Register AFR3 : 4;
			Device_Register AFR4 : 4;
			Device_Register AFR5 : 4;
			Device_Register AFR6 : 4;
			Device_Register AFR7 : 4;
		}AFRLs;
	};
	union {
		Device_Register AFRH : 32;
		struct{
			Device_Register AFR0 : 4;
			Device_Register AFR1 : 4;
			Device_Register AFR2 : 4;
			Device_Register AFR3 : 4;
			Device_Register AFR4 : 4;
			Device_Register AFR5 : 4;
			Device_Register AFR6 : 4;
			Device_Register AFR7 : 4;
		}AFRHs;
	};
};
//typedef struct
//{
//  uint32_t Pin;       /*!< Specifies the GPIO pins to be configured.
//                           This parameter can be any value of @ref GPIO_pins_define */
//
//  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins.
//                           This parameter can be a value of @ref GPIO_mode_define */
//
//  uint32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
//                           This parameter can be a value of @ref GPIO_pull_define */
//
//  uint32_t Speed;     /*!< Specifies the speed for the selected pins.
//                           This parameter can be a value of @ref GPIO_speed_define */
//
//  uint32_t Alternate;  /*!< Peripheral to be connected to the selected pins.
//                            This parameter can be a value of @ref GPIO_Alternate_function_selection */
//}GPIO_InitTypeDef;
struct GPIO_Init{
	GPIO::Port Port;
	struct Mode{
		GPIO::Mode Pin1 : 2;
		GPIO::Mode Pin2 : 2;
		GPIO::Mode Pin3 : 2;
		GPIO::Mode Pin4 : 2;
		GPIO::Mode Pin5 : 2;
		GPIO::Mode Pin6 : 2;
		GPIO::Mode Pin7 : 2;
		GPIO::Mode Pin8 : 2;
		GPIO::Mode Pin9 : 2;
		GPIO::Mode Pin10 : 2;
		GPIO::Mode Pin11 : 2;
		GPIO::Mode Pin12 : 2;
		GPIO::Mode Pin13 : 2;
		GPIO::Mode Pin14 : 2;
		GPIO::Mode Pin15 : 2;
	};
	struct Pull{
		GPIO::Pull Pin1 : 2;
		GPIO::Pull Pin2 : 2;
		GPIO::Pull Pin3 : 2;
		GPIO::Pull Pin4 : 2;
		GPIO::Pull Pin5 : 2;
		GPIO::Pull Pin6 : 2;
		GPIO::Pull Pin7 : 2;
		GPIO::Pull Pin8 : 2;
		GPIO::Pull Pin9 : 2;
		GPIO::Pull Pin10 : 2;
		GPIO::Pull Pin11 : 2;
		GPIO::Pull Pin12 : 2;
		GPIO::Pull Pin13 : 2;
		GPIO::Pull Pin14 : 2;
		GPIO::Pull Pin15 : 2;
	};
	struct Output_Type{
		GPIO::Output_Type Pin1 : 1;
		GPIO::Output_Type Pin2 : 1;
		GPIO::Output_Type Pin3 : 1;
		GPIO::Output_Type Pin4 : 1;
		GPIO::Output_Type Pin5 : 1;
		GPIO::Output_Type Pin6 : 1;
		GPIO::Output_Type Pin7 : 1;
		GPIO::Output_Type Pin8 : 1;
		GPIO::Output_Type Pin9 : 1;
		GPIO::Output_Type Pin10 : 1;
		GPIO::Output_Type Pin11 : 1;
		GPIO::Output_Type Pin12 : 1;
		GPIO::Output_Type Pin13 : 1;
		GPIO::Output_Type Pin14 : 1;
		GPIO::Output_Type Pin15 : 1;
	};
	struct Speed{
		GPIO::Speed Pin1 : 2;
		GPIO::Speed Pin2 : 2;
		GPIO::Speed Pin3 : 2;
		GPIO::Speed Pin4 : 2;
		GPIO::Speed Pin5 : 2;
		GPIO::Speed Pin6 : 2;
		GPIO::Speed Pin7 : 2;
		GPIO::Speed Pin8 : 2;
		GPIO::Speed Pin9 : 2;
		GPIO::Speed Pin10 : 2;
		GPIO::Speed Pin11 : 2;
		GPIO::Speed Pin12 : 2;
		GPIO::Speed Pin13 : 2;
		GPIO::Speed Pin14 : 2;
		GPIO::Speed Pin15 : 2;
	};
	uint32_t Alternate;
};
static_assert(sizeof(Device_Register) == 4, "Device_Register must be 4 bytes in size");
static_assert(alignof(Device_Register) == 4, "Device_Register must be word‐aligned");
static_assert(std::is_unsigned<Device_Register>::value, "Device_Register must be unsigned");
static_assert(sizeof(GPIO) == (10 * sizeof(Device_Register)), "Padding at GPIO class");
static_assert(std::is_standard_layout<GPIO>::value, "GPIO must be standart layout");
static_assert(sizeof(GPIO::Pin) == 2, "GPIO::Pin must be 2 bytes in size");
#endif /* CPPGPIO_GPIO_HPP_ */
