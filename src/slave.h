//
// Created by delta54 on 05.01.2019.
//

#ifndef MODBUS_BUS_H
#define MODBUS_BUS_H

#include <ModbusRtu.h>
#include "config.h"

// assign the Arduino pin that must be connected to RE-DE RS485 transceiver
#define TXEN    2

class Slave {
    Modbus modbus;

public:
    /**
    *  Modbus object declaration
    *  u8id : node id = 0 for master, = 1..247 for slave
    *  u8serno : serial port (use 0 for Serial)
    *  u8txenpin : 0 for RS-232 and USB-FTDI
    *               or any pin number > 1 for RS-485
    */
    Slave(uint8_t u8id = SLAVE_ID) {
        this->modbus = Modbus(u8id, 0, TXEN); // this is slave @1 and RS-485
    }

    void begin(long u32speed) {
        this->modbus.begin(u32speed);
    }

    void update() {
        this->modbus.poll(au16data, MODBUS_ARR_SIZE);
    }
};

#endif //MODBUS_BUS_H
