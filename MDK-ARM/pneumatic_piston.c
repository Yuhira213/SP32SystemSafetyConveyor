/* Includes ------------------------------------------------------------------*/
#include "pneumatic_piston.h"
#include "stm32f4xx_hal.h"  // Library HAL untuk STM32

/* Fungsi untuk mengaktifkan atau menonaktifkan Pneumatic Piston */
void control_pneumatic_piston(GPIO_PinState state)
{
    if (state == GPIO_PIN_SET) {  // Rule: INT13-C - Pembandingan dilakukan dengan tepat menggunakan `GPIO_PIN_SET` untuk memeriksa status pin.
        // Aktifkan Pneumatic Piston (misalnya, dengan menyalakan solenoid valve)
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);  // Rule: EXP33-C - Menggunakan perintah GPIO yang sesuai untuk mengaktifkan solenoid.
    }
		
    else {
        // Matikan Pneumatic Piston
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);  // Rule: EXP33-C - Menggunakan perintah GPIO yang sesuai untuk mematikan solenoid.
    }
}
