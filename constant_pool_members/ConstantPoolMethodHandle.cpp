#include "ConstantPoolMethodHandle.h"
#include "../endian_fix.h"

void ConstantPoolMethodHandle::printState() {
    std::cout << "MethodHandle: " << this->reference_kind << ":#" << this->reference_index << std::endl;
}

void ConstantPoolMethodHandle::initState(std::ifstream &inputStream) {
    inputStream.read(reinterpret_cast<char *>(&this->reference_kind), sizeof(this->reference_kind));
    toBigEndian(reinterpret_cast<char *>(&this->reference_kind), sizeof(this->reference_kind));
    inputStream.read(reinterpret_cast<char *>(&this->reference_index), sizeof(this->reference_index));
    toBigEndian(reinterpret_cast<char *>(&this->reference_index), sizeof(this->reference_index));
}

void ConstantPoolMethodHandle::printResolved() {
    //TODO
}
