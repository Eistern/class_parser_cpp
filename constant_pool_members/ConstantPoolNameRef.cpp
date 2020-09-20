#include "ConstantPoolNameRef.h"
#include "../endian_fix.h"

void ConstantPoolNameRef::printState() {
    switch (this->tag) {
        case 9:
            std::cout << "Fieldref";
            break;
        case 10:
            std::cout << "Methodref";
            break;
        case 11:
            std::cout << "InterfaceMethodref";
            break;
        case 12:
            std::cout << "NameAndType";
            break;
        case 18:
            std::cout << "InvokeDynamic";
            break;
        default:
            throw std::exception();
    }
    std::cout << ": #" << this->classIndex << ".#" << this->nameAndTypeIndex << std::endl;
}

void ConstantPoolNameRef::initState(std::ifstream &inputStream) {
    inputStream.read(reinterpret_cast<char *>(&this->classIndex), sizeof(this->classIndex));
    toBigEndian(reinterpret_cast<char *>(&this->classIndex), sizeof(this->classIndex));
    inputStream.read(reinterpret_cast<char *>(&this->nameAndTypeIndex), sizeof(this->nameAndTypeIndex));
    toBigEndian(reinterpret_cast<char *>(&this->nameAndTypeIndex), sizeof(this->nameAndTypeIndex));
}

ConstantPoolNameRef::ConstantPoolNameRef(uint8_t tag) : tag(tag) {
}
