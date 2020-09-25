#ifndef CLASS_PARSER_CPP_CONSTANTPOOLLONG_H
#define CLASS_PARSER_CPP_CONSTANTPOOLLONG_H

#include "ConstantPoolMember.h"

class ConstantPoolLong : public ConstantPoolMember {
private:
    uint32_t high_bytes = 0;
    uint32_t low_bytes = 0;
public:
    void initState(std::ifstream &inputStream) override;

    void printResolved() override;

    void printState() override;
};


#endif //CLASS_PARSER_CPP_CONSTANTPOOLLONG_H
