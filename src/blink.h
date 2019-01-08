
//
// Created by delta54 on 05.01.2019.
//

#ifndef MODBUS_BLINK_H
#define MODBUS_BLINK_H

#include <Arduino.h>

class Blink {
private:
    long previousMillis;
    uint8_t ledPin;
    long interval, on;
    uint8_t ledState = LOW;

public:
    Blink(uint8_t pin = 13, long interval = 2000, long on = 100) {
        this->interval = interval;
        this->ledPin = pin;
        this->on = on;

        pinMode(ledPin, OUTPUT);
        digitalWrite(ledPin, LOW);
    }

    void update() {
        unsigned long currentMillis = millis();

        if (currentMillis - this->previousMillis > interval) {
            this->previousMillis = currentMillis;

            if (this->ledState == LOW)
                this->ledState = HIGH;
            else
                this->ledState = LOW;

            digitalWrite(ledPin, this->ledState);
        }

        if (this->ledState == HIGH && (currentMillis - this->previousMillis > this->on)) {
            this->ledState = LOW;
            digitalWrite(ledPin, this->ledState);
        }
    }
};

#endif //MODBUS_BLINK_H
