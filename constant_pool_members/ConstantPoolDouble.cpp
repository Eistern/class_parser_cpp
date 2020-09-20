#include <cmath>
#include "ConstantPoolDouble.h"
#include "../endian_fix.h"

void ConstantPoolDouble::printState() {
    std::cout << "Double: ";
    int64_t bits = (int64_t) ((uint64_t) high_bytes << 32u) + low_bytes;

    if (bits == 0x7ff0000000000000L) {
        std::cout << "+INF" << std::endl;
        return;
    }
    if (bits == 0xfff0000000000000L) {
        std::cout << "-INF" << std::endl;
        return;
    }

    if ((bits > 0x7ff0000000000001L && bits <= 0x7fffffffffffffffL) ||
        (bits > 0xfff0000000000001L && bits <= 0xffffffffffffffffL)) {
        std::cout << "NaN" << std::endl;
    }

    int32_t s = (bits >> 63) == 0 ? 1 : -1;
    int32_t e = (bits >> 52u) & 0x7ffL;
    int64_t m = (e == 0) ?
                (bits & 0xfffffffffffffL) << 1u :
                (bits & 0xfffffffffffffL) | 0x10000000000000L;
    std::cout << s * m * std::exp2(e - 1075) << std::endl;
}

void ConstantPoolDouble::initState(std::ifstream &inputStream) {
    inputStream.read(reinterpret_cast<char *>(&this->high_bytes), sizeof(high_bytes));
    toBigEndian(reinterpret_cast<char *>(&this->high_bytes), sizeof(high_bytes));
    inputStream.read(reinterpret_cast<char *>(&this->low_bytes), sizeof(this->low_bytes));
    toBigEndian(reinterpret_cast<char *>(&this->low_bytes), sizeof(this->low_bytes));
}
