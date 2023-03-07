#include "mbed.h"
#include <cmath>

const double pi = 3.141592653589793238462;
const double amplitude = 0.5f;
const double offset = 39000.0 / 2;

// The sinewave is created on this pin
// Adjust analog output pin name to your board spec.
AnalogOut aout(PA_4);

int main()
{
    double rads = 0.0;
    uint16_t sample = 0;

    while (1) {
        // sinewave output
        for (int i = 0; i < 360; i++) {
            rads = (pi * i) / 180.0f;
            if (i < 180) {
                sample = (uint16_t)(3 * tanh(rads) * offset);
            } else {
                sample = (uint16_t)(3 * tanh(2.0 * pi - rads) * offset);
            }
            aout.write_u16(sample);
            wait_us(1);
        }
    }
}


