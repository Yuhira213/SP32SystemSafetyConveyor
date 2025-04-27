#ifndef PNEUMATIC_PISTON_H
#define PNEUMATIC_PISTON_H

#include <stdint.h>
#include <stdbool.h>

// Deklarasi fungsi untuk mengontrol piston
void control_pneumatic_piston(bool state);

// Deklarasi fungsi utama untuk memonitor dan mengontrol piston
void monitor_pneumatic_piston(void);

#endif /* PNEUMATIC_PISTON_H */