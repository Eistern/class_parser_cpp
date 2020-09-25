#ifndef CLASS_PARSER_CPP_CONSTANTPOOLMEMBER_H
#define CLASS_PARSER_CPP_CONSTANTPOOLMEMBER_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>

class ConstantPoolMember {
protected:
    std::map<uint16_t, ConstantPoolMember *> *owner_pool = nullptr;
public:
    virtual void printState() = 0;

    virtual void printResolved() = 0;

    virtual void initState(std::ifstream &inputStream) = 0;

    void setOwnerPool(std::map<uint16_t, ConstantPoolMember *> *pool) {
        this->owner_pool = pool;
    }
};

#endif //CLASS_PARSER_CPP_CONSTANTPOOLMEMBER_H
