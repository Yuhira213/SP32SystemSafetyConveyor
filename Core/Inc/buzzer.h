#ifndef BUZZER_H_
#define BUZZER_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

#define BUZZER_PIN         GPIO_PIN_3
#define BUZZER_GPIO_PORT   GPIOA

void Buzzer_Init(void);
void Buzzer_Control(uint8_t state);

#endif /* BUZZER_H_ */
