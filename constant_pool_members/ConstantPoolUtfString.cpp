#include "ConstantPoolUtfString.h"
#include "../endian_fix.h"
#include <string>

void ConstantPoolUtfString::initState(std::ifstream &inputStream) {
    inputStream.read(reinterpret_cast<char *>(&this->length), sizeof(length));
    toBigEndian(reinterpret_cast<char *>(&this->length), sizeof(length));

    this->data = new char[this->length];
    inputStream.read(this->data, sizeof(char) * this->length);
}

void ConstantPoolUtfString::printState() {
    std::cout << "Utf8: " << std::string(reinterpret_cast<char *>(this->data), this->length) << std::endl;
}

ConstantPoolUtfString::~ConstantPoolUtfString() {
    delete[] this->data;
}

void ConstantPoolUtfString::printResolved() {
    std::cout << std::string(reinterpret_cast<char *>(this->data), this->length);
}
