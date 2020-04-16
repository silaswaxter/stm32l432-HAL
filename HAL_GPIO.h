/*
INSTRUCTIONS:  Create an object of type GPIO_Type.  Populate
the struct's members with the configurations defined.
*/

#ifndef HAL_GPIO
#define HAL_GPIO

#include "stm32l432xx.h"
#include "RegisterMaskConstructors.h"

//Logic Levels
#define HIGH 1
#define LOW 0			
				
//GPIO MODES
#define GPIO_MODE_INPUT (0x00)
#define GPIO_MODE_OUTPUT (0x01)
#define GPIO_MODE_ALTFUNC (0x02)
#define GPIO_MODE_ANALOG (0x03)

#define GPIO_MODE_SECTLEN 2

//GPIO OUTPUT_TYPES
#define GPIO_OUTPUT_TYPE_PUSH (0x00)
#define GPIO_OUTPUT_TYPE_DRAIN (0x01)

#define GPIO_OUTPUT_TYPE_SECTLEN 1

//GPIO OUTPUT_SPEED
#define GPIO_OUTPUT_SPEED_LOW (0x00)
#define GPIO_OUTPUT_SPEED_MEDIUM (0x01)
#define GPIO_OUTPUT_SPEED_HIGH (0x02)
#define GPIO_OUTPUT_SPEED_VERYHIGH (0x03)

#define GPIO_OUTPUT_SPEED_SECTLEN 2

//GPIO PULL
#define GPIO_PULL_NONE (0x00)
#define GPIO_PULL_UP (0x01)
#define GPIO_PULL_DOWN (0x02)

#define GPIO_PULL_SECTLEN 2

//GPIO ALT_FUNCTION
#define GPIO_ALTFUNC_AF0 (0x00)
#define GPIO_ALTFUNC_AF1 (0x01)
#define GPIO_ALTFUNC_AF2 (0x02)
#define GPIO_ALTFUNC_AF3 (0x03)
#define GPIO_ALTFUNC_AF4 (0x04)
#define GPIO_ALTFUNC_AF5 (0x05)
#define GPIO_ALTFUNC_AF6 (0x06)
#define GPIO_ALTFUNC_AF7 (0x07)
#define GPIO_ALTFUNC_AF8 (0x08)
#define GPIO_ALTFUNC_AF9 (0x09)
#define GPIO_ALTFUNC_AF10 (0x0A)
#define GPIO_ALTFUNC_AF11 (0x0B)
#define GPIO_ALTFUNC_AF12 (0x0C)
#define GPIO_ALTFUNC_AF13 (0x0D)
#define GPIO_ALTFUNC_AF14 (0x0E)
#define GPIO_ALTFUNC_AF15 (0x0F)

#define GPIO_ALTFUNC_SECTLEN 4

typedef struct
{
	GPIO_TypeDef *port;		
	uint32_t pin;
	uint32_t mode;
	uint32_t output_Type; 	//push-pull vs open-drain
	uint32_t output_Speed;	//speed of output GPIO pin
	uint32_t pull;					//pull-up/pull-down resistors
	uint32_t altFunction;		//configures alternate function on pin
} GPIO_Type;

static uint32_t portRCCEnabled(uint32_t gpioPort_RCCENR_Pos);
static void enGPIOPortClock(GPIO_TypeDef *port);
static void set_mode(GPIO_Type *IOPin);
static void set_outputType(GPIO_Type *IOPin);
static void set_outputSpeed(GPIO_Type *IOPin);
static void set_pull(GPIO_Type *IOPin);
static void set_altFunc(GPIO_Type *IOPin);

void gpio_init(GPIO_Type *IOPin);
void gpio_writePin(GPIO_Type *IOPin, uint32_t state);

#endif //HAL_GPIO
