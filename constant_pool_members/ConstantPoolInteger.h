#ifndef CLASS_PARSER_CPP_CONSTANTPOOLINTEGER_H
#define CLASS_PARSER_CPP_CONSTANTPOOLINTEGER_H

#include "ConstantPoolMember.h"

class ConstantPoolInteger : public ConstantPoolMember {
private:
    uint32_t bytes;
public:
    void printState() override;

    void printResolved() override;

    void initState(std::ifstream &inputStream) override;
};


#endif //CLASS_PARSER_CPP_CONSTANTPOOLINTEGER_H
