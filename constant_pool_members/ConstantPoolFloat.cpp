#include "ConstantPoolFloat.h"
#include "../endian_fix.h"
#include <cmath>

void ConstantPoolFloat::printState() {
    std::cout << "Float: ";

    if (bytes == 0x7f800000) {
        std::cout << "+INF" << std::endl;
        return;
    }
    if (bytes == 0xff800000) {
        std::cout << "-INF" << std::endl;
    }
    if ((bytes > 0x7f800000 && bytes <= 0x7fffffff) || (bytes > 0xff800001 && bytes <= 0xffffffff)) {
        std::cout << "NaN" << std::endl;
    }

    int s = ((bytes >> 31u) == 0) ? 1 : -1;
    int e = ((bytes >> 23u) & 0xff);
    int m = (e == 0) ?
            (bytes & 0x7fffff) << 1u :
            (bytes & 0x7fffff) | 0x800000;
    std::cout << s * m * std::exp2(e - 150) << std::endl;
}

void ConstantPoolFloat::initState(std::ifstream &inputStream) {
    inputStream.read(reinterpret_cast<char *>(&this->bytes), sizeof(this->bytes));
    toBigEndian(reinterpret_cast<char *>(&this->bytes), sizeof(this->bytes));
}
