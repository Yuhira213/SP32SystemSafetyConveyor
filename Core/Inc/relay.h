#ifndef RELAY_H_
#define RELAY_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

// === Makro Pin Relay ===
#define RELAY_PIN         GPIO_PIN_1
#define RELAY_GPIO_PORT   GPIOA

void Relay_Init(void);
void Relay_Control(uint8_t state);  // 1 = ON, 0 = OFF

#endif /* RELAY_H_ */