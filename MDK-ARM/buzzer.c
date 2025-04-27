#include "buzzer.h"

void Buzzer_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};  // Rule: DCL31-C - Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.

    __HAL_RCC_GPIOA_CLK_ENABLE();  // Rule: MSC30-C - Pastikan clock untuk GPIO port A diaktifkan sebelum digunakan.

    GPIO_InitStruct.Pin = BUZZER_PIN;  // Rule: STR30-C - Penamaan pin untuk buzzer harus jelas dan deskriptif.
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  // Rule: EXP33-C - Menetapkan mode pin sebagai output push-pull sesuai dengan kebutuhan buzzer.
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Rule: EXP33-C - Tidak menggunakan pull-up atau pull-down resistor pada pin buzzer.
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;  // Rule: EXP33-C - Menetapkan kecepatan pin output ke level rendah.

    HAL_GPIO_Init(BUZZER_GPIO_PORT, &GPIO_InitStruct);  // Rule: EXP33-C - Inisialisasi pin buzzer sesuai dengan konfigurasi yang ditetapkan.

    HAL_GPIO_WritePin(BUZZER_GPIO_PORT, BUZZER_PIN, GPIO_PIN_RESET);  // Rule: DCL31-C - Mengatur nilai pin buzzer dengan tepat setelah inisialisasi.
}

void Buzzer_Control(uint8_t state) {
    if (state != 0U) {  // Rule: INT13-C - Pastikan pembandingan dilakukan dengan tepat menggunakan `state != 0U`.
        HAL_GPIO_WritePin(BUZZER_GPIO_PORT, BUZZER_PIN, GPIO_PIN_SET);  // Menyalakan buzzer jika state tidak nol.
    } else {
        HAL_GPIO_WritePin(BUZZER_GPIO_PORT, BUZZER_PIN, GPIO_PIN_RESET);  // Mematikan buzzer jika state nol.
    }
}
