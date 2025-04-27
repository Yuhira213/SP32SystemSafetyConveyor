/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PNEUMATIC_PISTON_H
#define __PNEUMATIC_PISTON_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"  // Untuk akses pin GPIO

/* Exported types ------------------------------------------------------------*/
/* Fungsi untuk mengaktifkan atau menonaktifkan Pneumatic Piston */
void control_pneumatic_piston(GPIO_PinState state);

#endif /* __PNEUMATIC_PISTON_H */
