#include "blink.h"
#include "slave.h"
#include "toggles.h"
#include "temp.h"

//static int serial_fputchar(const char ch, FILE *stream) { Serial.write(ch); return ch; }
//static FILE *serial_stream = fdevopen(serial_fputchar, NULL);


Blink led13 = Blink();
Slave slave = Slave();
Toggles toggles = Toggles();
Temp temp = Temp();

void setup() {
//    stdout = serial_stream; // эта строка первая в setup

    slave.begin(19200);
    Serial.begin(19200);
}

void loop() {
    while (1) {
        slave.update();
        toggles.update();
        temp.update();
        led13.update();
    }
}