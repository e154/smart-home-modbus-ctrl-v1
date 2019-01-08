//
// Created by delta54 on 05.01.2019.
//

#ifndef MODBUS_BUTTONS_H
#define MODBUS_BUTTONS_H

#include <Arduino.h>

#define A_BTN_NULL    0
#define A_BTN_1       1
#define A_BTN_2       2
#define A_BTN_3       3
#define A_BTN_4       4
#define A_BTN_5       5

class AButtons {
    uint8_t interval, pin;
    volatile uint8_t btnBuf;
    long previousMillis;

public:
    AButtons(uint8_t pin, uint8_t interval = 50) {
        this->interval = interval;
        this->pin = pin;
        analogReference(DEFAULT);
    };

    void update() {
        unsigned long currentMillis = millis();

        if (currentMillis - this->previousMillis < this->interval) {
            return;
        }

        this->previousMillis = currentMillis;

        int analogValue;
        // 0 ... 1023
        analogValue = analogRead(0);

        Serial.println("analogValue: ");
        Serial.println(analogValue);

        // проверка нажатия
        uint8_t btn = A_BTN_NULL;
        if (analogValue > 900)
            btn = A_BTN_1;
        else if (analogValue > 800)
            btn = A_BTN_2;
        else if (analogValue > 600)
            btn = A_BTN_3;
        else if (analogValue > 500)
            btn = A_BTN_4;
        else if (analogValue > 200)
            btn = A_BTN_5;

        static uint8_t lastBtn, count;

        // дребезг
        if (btn == A_BTN_NULL) {
            lastBtn = A_BTN_NULL;
            btnBuf = A_BTN_NULL;
            count = 0;
            return;
        }
        if (btn == lastBtn) {
            count++;
            if (count > 10) {
                count = 0;
                this->btnBuf = btn;
            }
        } else {
            lastBtn = btn;
            count = 0;
        }

        this->press();
    }

    void press() {

        switch (this->btnBuf) {
            case A_BTN_1: {
                Serial.println("btn 1");
                break;
            }
            case A_BTN_2: {
                Serial.println("btn 2");
                break;
            }
            case A_BTN_3: {
                Serial.println("btn 3");
                break;
            }
            case A_BTN_4: {
                Serial.println("btn 4");
                break;
            }
            case A_BTN_5: {
                Serial.println("btn 5");
                break;
            }
            default:
                break;
        }
    };
};

#endif //MODBUS_BUTTONS_H
