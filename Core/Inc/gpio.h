/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
// Kamu bisa tambahkan include tambahan di sini jika perlu
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
// Tambahkan definisi pin atau makro jika diperlukan
// Misal: #define LED_Pin GPIO_PIN_13
//        #define LED_GPIO_Port GPIOC
/* USER CODE END Private defines */

/**
  * @brief  Inisialisasi semua GPIO
  */
void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
// Tambahkan prototype fungsi tambahan jika ada
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /* __GPIO_H__ */
