#include "ConstantPoolLinkMember.h"
#include "../endian_fix.h"

void ConstantPoolLinkMember::printState() {
    switch (this->tag) {
        case 7:
            std::cout << "Class";
            break;
        case 8:
            std::cout << "String";
            break;
        case 16:
            std::cout << "MethodType";
            break;
        default:
            throw std::exception();
    }
    std::cout << ": #" << this->nameIndex << " // ";
    printResolved();
    std::cout << std::endl;
}

void ConstantPoolLinkMember::initState(std::ifstream &inputStream) {
    inputStream.read(reinterpret_cast<char *>(&this->nameIndex), sizeof(this->nameIndex));
    toBigEndian(reinterpret_cast<char *>(&this->nameIndex), sizeof(this->nameIndex));
}

ConstantPoolLinkMember::ConstantPoolLinkMember(uint8_t tag) : tag(tag) {
}

void ConstantPoolLinkMember::printResolved() {
    (*this->owner_pool)[this->nameIndex]->printResolved();
}
