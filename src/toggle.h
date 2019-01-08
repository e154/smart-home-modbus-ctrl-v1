//
// Created by delta54 on 05.01.2019.
//

#ifndef MODBUS_TOGGLE_H
#define MODBUS_TOGGLE_H

#include <Arduino.h>

// обычный выключатель 220В, с фиксированным положением
//
//          /
//         /
// o------/   |------o
//

class Toggle {
private:
    uint8_t interval, togglePin, lightPin, counter;
    long previousMillis;
    bool enabled;
    int oldStatus, status, statusLight;

public:
    Toggle(uint8_t togglePin, uint8_t lightPin, uint8_t interval = 50) {
        Serial.println("init toggle");

        this->interval = interval;
        this->togglePin = togglePin;
        this->lightPin = lightPin;

        // назначаем режим работы пина- вход с подтяжкой
        pinMode(this->togglePin, INPUT_PULLUP);

        // назначаем режим работы пина- выход
        pinMode(this->lightPin, OUTPUT);
        digitalWrite(this->lightPin, LOW);
    };

    void update() {
        unsigned long currentMillis = millis();

        if (currentMillis - this->previousMillis < interval) {
            return;
        }

        this->previousMillis = currentMillis;

        status = digitalRead(this->togglePin);

        if (status == oldStatus && status != statusLight) {
            counter++;
            if (counter > 10) {
                statusLight = status;
                counter = 0;
                this->setLight(!enabled);
            }
        } else {
            counter = 0;
            oldStatus = status;
        }
    };

    void setLight(bool enabled) {
        if (enabled == this->enabled) {
            return;
        }

        Serial.println("toggle: ");

        this->enabled = enabled;

        if (this->enabled) {
            digitalWrite(this->lightPin, HIGH);
        } else {
            digitalWrite(this->lightPin, LOW);
        }
    }

    bool getLightStatus() {
        return this->enabled;
    }
};

#endif //MODBUS_TOGGLE_H
