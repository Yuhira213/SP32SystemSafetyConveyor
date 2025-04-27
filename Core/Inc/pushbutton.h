#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

#define BUTTON_PIN         GPIO_PIN_2
#define BUTTON_GPIO_PORT   GPIOA

void PushButton_Init(void);
uint8_t PushButton_Read(void);

#endif /* PUSHBUTTON_H_ */
