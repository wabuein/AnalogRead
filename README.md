# PWM Control with Potentiometer

A simple mbed project that uses a potentiometer to adjust the PWM duty cycle for controlling devices like LEDs or motors in real time.

---

## 🧠 Overview

* Reads an analog value from a potentiometer.
* Maps that value to a PWM duty cycle on an output pin.
* Displays the duty cycle percentage via the serial monitor.
* Can be used for LED brightness or motor speed control.

---

## ⚙️ Hardware Requirements

* Mbed-compatible microcontroller (e.g., NUCLEO board)
* Potentiometer (≈10 kΩ)
* Breadboard and jumper wires

### Pin Connections

| Component            | Pin  | Description       |
| -------------------- | ---- | ----------------- |
| Potentiometer output | A0   | Analog input      |
| PWM output           | PB_4 | PWM signal output |
| Onboard LED          | LED1 | Status indicator  |
| Power                | 3.3V | Potentiometer VCC |
| Ground               | GND  | Common ground     |

---

## ▶️ How to Use

1. Open the code in **Mbed Studio** or the **Mbed Online Compiler**.
2. Connect the board and flash the program.
3. Open a serial monitor (9600 baud) to view duty cycle updates.
4. Rotate the potentiometer to vary the PWM signal.

---

## 🧩 Code Reference

```cpp
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
```

---

## 📄 Attribution

```cpp
// ENGR202: pwm output using nucleo  
// Originally Ekky Hermestian IW  
// Tilly Alton 16/10/2023  
// This code causes the built-in LED to blink.  
// The actual code is written outside the while loop but executed by calling the function blink.  
// An adaptation of bare-metal blinky, modified for PWM signal control.
```

---

## 🧱 Project Structure

```
├── main.cpp
├── README.md
└── mbed-os/
```

---

### License

Open-source and free to use for educational purposes.
Credit retained per original author attribution above.
