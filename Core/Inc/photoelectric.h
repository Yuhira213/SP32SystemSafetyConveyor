#ifndef PHOTOELECTRIC_H_
#define PHOTOELECTRIC_H_

#include <stdint.h>   // INT02-C: Gunakan tipe pasti seperti uint8_t
#include "stm32f4xx_hal.h"  // Untuk akses ke HAL GPIO

// === Makro Pin Sensor ===
#define PHOTOELECTRIC_PIN        GPIO_PIN_0
#define PHOTOELECTRIC_GPIO_PORT  GPIOA

// === API Fungsi ===

/*
 * @brief Inisialisasi sensor photoelectric.
 * @note  Harus dipanggil sekali di awal program sebelum digunakan.
 */
void Photoelectric_Init(void);

/*
 * @brief Membaca status sensor (terhalang atau tidak).
 * @retval 1 jika sinar terhalang (objek terdeteksi), 0 jika tidak.
 */
uint8_t Photoelectric_Read(void);

#endif /* PHOTOELECTRIC_H_ */
