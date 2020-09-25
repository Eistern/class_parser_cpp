#ifndef CLASS_PARSER_CPP_CONSTANTPOOLFLOAT_H
#define CLASS_PARSER_CPP_CONSTANTPOOLFLOAT_H

#include "ConstantPoolMember.h"

class ConstantPoolFloat : public ConstantPoolMember {
private:
    uint32_t bytes;
public:
    void printState() override;

    void printResolved() override;

    void initState(std::ifstream &inputStream) override;
};


#endif //CLASS_PARSER_CPP_CONSTANTPOOLFLOAT_H
