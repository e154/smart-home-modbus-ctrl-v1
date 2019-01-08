//
// Created by delta54 on 08.01.2019.
//

#ifndef MODBUS_LM35_H
#define MODBUS_LM35_H

#include <Arduino.h>
#include "common.h"

class Lm35 {

    uint8_t pin;
    float temp;
public:
    Lm35(uint8_t pin) {
        this->pin = pin;
    };

    void update() {
        int raw;
        raw = analogRead(this->pin);
        // todo x/100
        this->temp = (raw / 1023.0) * 5.0 * 1000;
    }

    float getTemp() {
        return this->temp;
    }
};

#endif //MODBUS_LM35_H
