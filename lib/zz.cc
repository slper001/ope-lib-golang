#include <string>
#include <NTL/ZZ.h>

using namespace NTL;

std::string
StringFromZZ(const ZZ &x)
{
    std::string s;
    s.resize(NumBytes(x), 0);
    BytesFromZZ(reinterpret_cast<uint8_t *>(&s[0]), x, s.length());
    return s;
}

ZZ
ZZFromString(const std::string &s)
{
    return ZZFromBytes(reinterpret_cast<const uint8_t *>(s.data()),
                       s.length());
}

ZZ
ZZFromUint64 (uint64_t value)
{
    const unsigned int unit = 256;
    ZZ power;
    power = 1;
    ZZ res;
    res = 0;

    while (value > 0) {
        res = res + (value % unit) * power;
        power = power * unit;
        value = value / unit;
    }
    return res;

}

uint64_t
uint64FromZZ(ZZ val)
{
    uint64_t res = 0;
    uint64_t mul = 1;
    while (val > 0) {
        res = res + mul*(to_int(val % 10));
        mul = mul * 10;
        val = val / 10;
    }
    return res;
}