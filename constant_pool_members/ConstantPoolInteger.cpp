#include "ConstantPoolInteger.h"
#include "../endian_fix.h"

void ConstantPoolInteger::printState() {
    std::cout << "Integer: " << this->bytes << std::endl;
}

void ConstantPoolInteger::initState(std::ifstream &inputStream) {
    inputStream.read(reinterpret_cast<char *>(&this->bytes), sizeof(this->bytes));
    toBigEndian(reinterpret_cast<char *>(&this->bytes), sizeof(this->bytes));
}

void ConstantPoolInteger::printResolved() {

}
