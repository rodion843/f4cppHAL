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
	enum Port {Port_A, Port_B, Port_C, Port_D, Port_E, Port_F, Port_G, Port_I};
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
	enum Pull{
		No_Up_Down,
		Pull_Up,
		Pull_Down
	};
	enum AlternateFunction{
		AF0,
		AF1,
		AF2,
		AF3,
		AF4,
		AF5,
		AF6,
		AF7,
		AF8,
		AF9,
		AF10,
		AF11,
		AF12,
		AF13,
		AF14,
		AF15,
	};
	GPIO(GPIO_Init gpio);
	void *operator new(size_t, Port port);
	void TogglePin(Pin pin);
	Pin GetPin(Pin pin) const;
	void SetPin(Pin pin);
	void ResetPin(Pin pin);
	void TogglePort();

	constexpr void StaticAssert();
private:
	union {
		Device_Register reg : 32;
		struct{
			volatile Mode Pin_0 : 2;
			volatile Mode Pin_1 : 2;
			volatile Mode Pin_2 : 2;
			volatile Mode Pin_3 : 2;
			volatile Mode Pin_4 : 2;
			volatile Mode Pin_5 : 2;
			volatile Mode Pin_6 : 2;
			volatile Mode Pin_7 : 2;
			volatile Mode Pin_8 : 2;
			volatile Mode Pin_9 : 2;
			volatile Mode Pin_10 : 2;
			volatile Mode Pin_11 : 2;
			volatile Mode Pin_12 : 2;
			volatile Mode Pin_13 : 2;
			volatile Mode Pin_14 : 2;
			volatile Mode Pin_15 : 2;
		}str;
	}MODER;
	union {
		Device_Register reg : 16;
		struct{
			volatile Output_Type Pin_0 : 1;
			volatile Output_Type Pin_1 : 1;
			volatile Output_Type Pin_2 : 1;
			volatile Output_Type Pin_3 : 1;
			volatile Output_Type Pin_4 : 1;
			volatile Output_Type Pin_5 : 1;
			volatile Output_Type Pin_6 : 1;
			volatile Output_Type Pin_7 : 1;
			volatile Output_Type Pin_8 : 1;
			volatile Output_Type Pin_9 : 1;
			volatile Output_Type Pin_10 : 1;
			volatile Output_Type Pin_11 : 1;
			volatile Output_Type Pin_12 : 1;
			volatile Output_Type Pin_13 : 1;
			volatile Output_Type Pin_14 : 1;
			volatile Output_Type Pin_15 : 1;
		}str;
	}OTYPER;
	union {
		Device_Register reg : 32;
		struct{
			volatile Speed Pin_0 : 2;
			volatile Speed Pin_1 : 2;
			volatile Speed Pin_2 : 2;
			volatile Speed Pin_3 : 2;
			volatile Speed Pin_4 : 2;
			volatile Speed Pin_5 : 2;
			volatile Speed Pin_6 : 2;
			volatile Speed Pin_7 : 2;
			volatile Speed Pin_8 : 2;
			volatile Speed Pin_9 : 2;
			volatile Speed Pin_10 : 2;
			volatile Speed Pin_11 : 2;
			volatile Speed Pin_12 : 2;
			volatile Speed Pin_13 : 2;
			volatile Speed Pin_14 : 2;
			volatile Speed Pin_15 : 2;
		}str;
	}OSPEEDR;
	union {
		Device_Register reg : 32;
		struct{
			volatile Pull PIN_0 : 2;
			volatile Pull PIN_1 : 2;
			volatile Pull PIN_2 : 2;
			volatile Pull PIN_3 : 2;
			volatile Pull PIN_4 : 2;
			volatile Pull PIN_5 : 2;
			volatile Pull PIN_6 : 2;
			volatile Pull PIN_7 : 2;
			volatile Pull PIN_8 : 2;
			volatile Pull PIN_9 : 2;
			volatile Pull PIN_10 : 2;
			volatile Pull PIN_11 : 2;
			volatile Pull PIN_12 : 2;
			volatile Pull PIN_13 : 2;
			volatile Pull PIN_14 : 2;
			volatile Pull PIN_15 : 2;
		}str;
	}PUPDR;
	union {
//		Device_Register reserved;
		Device_Register reg : 16;
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
		}str;
	}IDR;
	union {
//		Device_Register reserved;
		Device_Register reg : 16;
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
		}str;
	}ODR;
	union {
		Device_Register reg : 32;
		struct{
			Device_Register Set : 16;
			Device_Register Reset : 16;
		}str;
	}BSRR;
	union {
//		Device_Register reserved;
		Device_Register reg : 17;
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
		}str;
	}LCKR;
	union {								//TODO: can be set as a 64 bit interger?
		Device_Register reg : 32;
		struct{
			volatile AlternateFunction AFR0 : 4;
			volatile AlternateFunction AFR1 : 4;
			volatile AlternateFunction AFR2 : 4;
			volatile AlternateFunction AFR3 : 4;
			volatile AlternateFunction AFR4 : 4;
			volatile AlternateFunction AFR5 : 4;
			volatile AlternateFunction AFR6 : 4;
			volatile AlternateFunction AFR7 : 4;
		}str;
	}AFRL;
	union {
		Device_Register reg : 32;
		struct{
			volatile AlternateFunction AFR8 : 4;
			volatile AlternateFunction AFR9 : 4;
			volatile AlternateFunction AFR10 : 4;
			volatile AlternateFunction AFR11 : 4;
			volatile AlternateFunction AFR12 : 4;
			volatile AlternateFunction AFR13 : 4;
			volatile AlternateFunction AFR14 : 4;
			volatile AlternateFunction AFR15 : 4;
		}str;
	}AFRH;

	static_assert(sizeof(AFRL) == 4, "Device_Register must be 4 bytes in size");
	static_assert(sizeof(AFRH) == 4, "Device_Register must be 4 bytes in size");
	static_assert(sizeof(LCKR) == 4, "Device_Register must be 4 bytes in size");
	static_assert(sizeof(BSRR) == 4, "Device_Register must be 4 bytes in size");
	static_assert(sizeof(ODR) == 4, "Device_Register must be 4 bytes in size");
	static_assert(sizeof(IDR) == 4, "Device_Register must be 4 bytes in size");
	static_assert(sizeof(PUPDR) == 4, "Device_Register must be 4 bytes in size");
	static_assert(sizeof(OSPEEDR) == 4, "Device_Register must be 4 bytes in size");
	static_assert(sizeof(OTYPER) == 4, "Device_Register must be 4 bytes in size");
	static_assert(sizeof(MODER) == 4, "Device_Register must be 4 bytes in size");
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
	union {
		struct {
			GPIO::Mode Pin0 : 2;
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
		}str;
		uint32_t reg;
	}Mode;
	union{
		struct {
			GPIO::Output_Type Pin0 : 1;
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
		}str;
		uint16_t reg;
	}Output_Type;

	union{

		struct {
			GPIO::Speed Pin0 : 2;
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
		}str;
		uint32_t reg;
	}Speed;
	union{

		struct {
			GPIO::Pull Pin0 : 2;
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
		}str;
		uint32_t reg;
	}Pull;
	union{

		struct {
			GPIO::AlternateFunction Pin0 : 4;
			GPIO::AlternateFunction Pin1 : 4;
			GPIO::AlternateFunction Pin2 : 4;
			GPIO::AlternateFunction Pin3 : 4;
			GPIO::AlternateFunction Pin4 : 4;
			GPIO::AlternateFunction Pin5 : 4;
			GPIO::AlternateFunction Pin6 : 4;
			GPIO::AlternateFunction Pin7 : 4;
		}str;
		uint32_t reg;
	}AlternateLow;
	union{

		struct {
			GPIO::AlternateFunction Pin8 : 4;
			GPIO::AlternateFunction Pin9 : 4;
			GPIO::AlternateFunction Pin10 : 4;
			GPIO::AlternateFunction Pin11 : 4;
			GPIO::AlternateFunction Pin12 : 4;
			GPIO::AlternateFunction Pin13 : 4;
			GPIO::AlternateFunction Pin14 : 4;
			GPIO::AlternateFunction Pin15 : 4;
		}str;
		uint32_t reg;
	}AlternateHigh;
};
#endif /* CPPGPIO_GPIO_HPP_ */
