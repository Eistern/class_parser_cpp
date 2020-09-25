#ifndef CLASS_PARSER_CPP_CONSTANTPOOLMEMBER_H
#define CLASS_PARSER_CPP_CONSTANTPOOLMEMBER_H

#include <cstdint>
#include <fstream>
#include <iostream>

class ConstantPoolMember {
public:
    virtual void printState() = 0;

    virtual void printResolved() = 0;

    virtual void initState(std::ifstream &inputStream) = 0;
};

#endif //CLASS_PARSER_CPP_CONSTANTPOOLMEMBER_H
