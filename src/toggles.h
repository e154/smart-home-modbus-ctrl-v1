//
// Created by delta54 on 05.01.2019.
//

#ifndef MODBUS_TOGGLES_H
#define MODBUS_TOGGLES_H

#include "toggle.h"
#include "config.h"

class Toggles {
private:
    Toggle pull[TOTAL_TOGGLES] = {Toggle(TOGGLE1_PIN, TOGGLE1_LIGHT_PIN),
                                  Toggle(TOGGLE2_PIN, TOGGLE2_LIGHT_PIN),
                                  Toggle(TOGGLE3_PIN, TOGGLE3_LIGHT_PIN),
                                  Toggle(TOGGLE4_PIN, TOGGLE4_LIGHT_PIN),
                                  Toggle(TOGGLE5_PIN, TOGGLE5_LIGHT_PIN)
    };
public:
    Toggles() {};

    void update() {
        deserialize(au16data, MODBUS_ARR_SIZE);

        for (uint8_t i = 0; i < TOTAL_TOGGLES; i++) {
            pull[i].update();
        }

        serialize(au16data, MODBUS_ARR_SIZE);
    };

    void serialize(uint16_t *regs, uint8_t u8size) {
        for (uint8_t i = 0; i < TOTAL_TOGGLES; i++) {
            uint8_t v = 0;
            if (pull[i].getLightStatus()) {
                v = 1;
            };
            regs[i] = v;
        }
    }

    void deserialize(uint16_t *regs, uint8_t u8size) {
        for (uint8_t i = 0; i < TOTAL_TOGGLES; i++) {
            pull[i].setLight(regs[i] == 1);
        }
    }
};

#endif //MODBUS_TOGGLES_H
