#ifndef CLASS_PARSER_CPP_CONSTANTPOOLLONG_H
#define CLASS_PARSER_CPP_CONSTANTPOOLLONG_H


#include "ConstantPoolMember.h"

class ConstantPoolLong : public ConstantPoolMember {
private:
    uint32_t high_bytes;
    uint32_t low_bytes;
public:
    void initState(std::ifstream &inputStream) override;

    void printState() override;
};


#endif //CLASS_PARSER_CPP_CONSTANTPOOLLONG_H
