#include "relay.h"

void Relay_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};  // Rule: DCL31-C - Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.

    __HAL_RCC_GPIOA_CLK_ENABLE();  // Rule: MSC30-C - Pastikan clock untuk GPIO port A diaktifkan sebelum digunakan.

    GPIO_InitStruct.Pin = RELAY_PIN;  // Rule: STR30-C - Penamaan pin untuk relay harus jelas dan deskriptif.
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  // Rule: EXP33-C - Pastikan mode pin diatur sebagai output push-pull sesuai kebutuhan.
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Rule: EXP33-C - Tidak menggunakan pull-up atau pull-down pada pin relay.
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;  // Rule: EXP33-C - Menetapkan kecepatan pin output ke level rendah.

    HAL_GPIO_Init(RELAY_GPIO_PORT, &GPIO_InitStruct);  // Rule: EXP33-C - Inisialisasi pin relay sesuai dengan konfigurasi.

    HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY_PIN, GPIO_PIN_RESET);  // Rule: DCL31-C - Mengatur nilai pin relay dengan tepat.
}

void Relay_Control(uint8_t state) {
    if (state != 0U) {  // Rule: INT13-C - Pastikan pembandingan dilakukan dengan benar (nilai 0 untuk matikan relay, selain 0 untuk hidupkan).
        HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY_PIN, GPIO_PIN_SET);   // ON
    } else {
        HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY_PIN, GPIO_PIN_RESET); // OFF
    }
}