#ifndef CLASS_PARSER_CPP_CONSTANTPOOLMETHODHANDLE_H
#define CLASS_PARSER_CPP_CONSTANTPOOLMETHODHANDLE_H

#include "ConstantPoolMember.h"

class ConstantPoolMethodHandle : public ConstantPoolMember {
private:
    uint8_t reference_kind = 0;
    uint16_t reference_index = 0;
public:
    void printState() override;

    void printResolved() override;

    void initState(std::ifstream &inputStream) override;
};


#endif //CLASS_PARSER_CPP_CONSTANTPOOLMETHODHANDLE_H
