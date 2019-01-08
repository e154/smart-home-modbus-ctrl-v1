//
// Created by delta54 on 08.01.2019.
//

#ifndef MODBUS_TEMP_H
#define MODBUS_TEMP_H

#include "lm35.h"
#include "config.h"

class Temp {
    uint8_t interval = 100;
    long previousMillis;
    Lm35 pull[TOTAL_TEMP_SENSOR] = {Lm35(TEMP1_PIN), Lm35(TEMP2_PIN)};
public:
    Temp() {};

    void update() {
        unsigned long currentMillis = millis();

        if (currentMillis - this->previousMillis < interval) {
            return;
        }

        this->previousMillis = currentMillis;

        for (uint8_t i = 0; i < TOTAL_TEMP_SENSOR; i++) {
            pull[i].update();
        }
        serialize(au16data, MODBUS_ARR_SIZE);
    };

    void serialize(uint16_t *regs, uint8_t u8size) {
        uint16_t req[2] = {0, 0};
        uint8_t k;
        float temp;
        for (uint8_t i = 0; i < TOTAL_TEMP_SENSOR; i++) {
            k = TOTAL_TOGGLES;
            if (i != 0) {
                k = TOTAL_TOGGLES + 2 * i;
            }
            temp = pull[i].getTemp();
            encodeFloat(req, temp);
            regs[k] = req[0];
            regs[k + 1] = req[1];
        }
    };
};


#endif //MODBUS_TEMP_H
