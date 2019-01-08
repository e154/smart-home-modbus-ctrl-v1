//
// Created by delta54 on 08.01.2019.
//

#ifndef MODBUS_CONFIG_H
#define MODBUS_CONFIG_H

#include <pins_arduino.h>

// data array for modbus network sharing
uint16_t au16data[16] = {
        0, 0, 0, 0, 0, //toggles
        0, 0, // temp1
        0, 0, // temp2
        0, 0, 0, 0, 0, 0, 1};
#define MODBUS_ARR_SIZE 16

// temp sensors
#define TOTAL_TEMP_SENSOR 2
#define TEMP1_PIN (uint8_t)A0
#define TEMP2_PIN (uint8_t)A1

// toggles
#define TOTAL_TOGGLES 5
#define TOGGLE1_PIN 8
#define TOGGLE1_LIGHT_PIN 3
#define TOGGLE2_PIN 9
#define TOGGLE2_LIGHT_PIN 4
#define TOGGLE3_PIN 10
#define TOGGLE3_LIGHT_PIN 5
#define TOGGLE4_PIN 11
#define TOGGLE4_LIGHT_PIN 6
#define TOGGLE5_PIN 12
#define TOGGLE5_LIGHT_PIN 7

#endif //MODBUS_CONFIG_H
