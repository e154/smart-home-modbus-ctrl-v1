//
// Created by delta54 on 08.01.2019.
//

#ifndef MODBUS_COMMON_H
#define MODBUS_COMMON_H

union Pun {float f; uint32_t u;};

void encodeFloat(uint16_t *regs, float x)
{
    union Pun pun;

    pun.f = x;
    regs[0] = (pun.u >> 16) & 0xFFFFU;
    regs[1] = pun.u & 0xFFFFU;
}

float decodeFloat(const uint16_t *regs)
{
    union Pun pun;

    pun.u = ((uint32_t)regs[0] << 16) | regs[1];
    return pun.f;
}

#endif //MODBUS_COMMON_H
