#include "ConstantPoolLong.h"
#include "../endian_fix.h"

void ConstantPoolLong::printState() {
    std::cout << "Long: " << (int64_t) ((uint64_t) high_bytes << 32u) + low_bytes;
}

void ConstantPoolLong::initState(std::ifstream &inputStream) {
    inputStream.read(reinterpret_cast<char *>(&this->high_bytes), sizeof(high_bytes));
    toBigEndian(reinterpret_cast<char *>(&this->high_bytes), sizeof(high_bytes));
    inputStream.read(reinterpret_cast<char *>(&this->low_bytes), sizeof(this->low_bytes));
    toBigEndian(reinterpret_cast<char *>(&this->low_bytes), sizeof(this->low_bytes));
}
