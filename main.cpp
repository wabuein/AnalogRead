#include "mbed.h"

PwmOut mypwm(PB_4);
AnalogIn potentiometer(A0);
DigitalOut myled(LED1);

int main() {
    mypwm.period_ms(20);

    while (true) {
        float pot_value = potentiometer.read();
        mypwm.write(pot_value);

        printf("Duty cycle set to %.2f\n", pot_value * 100);
        thread_sleep_for(100);
    }
}