#include "pushbutton.h"

void PushButton_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};  // Rule: DCL31-C - Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.

    __HAL_RCC_GPIOA_CLK_ENABLE();  // Rule: MSC30-C - Pastikan clock untuk GPIO port A diaktifkan sebelum digunakan.

    GPIO_InitStruct.Pin = BUTTON_PIN;  // Rule: STR30-C - Penamaan pin untuk push button harus jelas dan deskriptif.
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;  // Rule: EXP33-C - Menetapkan mode pin sebagai input sesuai dengan fungsinya.
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // Rule: EXP33-C - Tidak menggunakan pull-up atau pull-down resistor pada pin push button.

    HAL_GPIO_Init(BUTTON_GPIO_PORT, &GPIO_InitStruct);  // Rule: EXP33-C - Inisialisasi pin push button sesuai dengan konfigurasi yang ditetapkan.
}

uint8_t PushButton_Read(void) {
    GPIO_PinState state = HAL_GPIO_ReadPin(BUTTON_GPIO_PORT, BUTTON_PIN);  // Rule: EXP33-C - Pastikan pembacaan pin dilakukan dengan benar.

    return (state == GPIO_PIN_RESET) ? 1U : 0U;  // Rule: INT13-C - Pembandingan dilakukan dengan tepat untuk menentukan apakah tombol ditekan atau tidak.
}
