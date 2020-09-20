#ifndef CLASS_PARSER_CPP_CONSTANTPOOLLINKMEMBER_H
#define CLASS_PARSER_CPP_CONSTANTPOOLLINKMEMBER_H

#include <cstdint>
#include "ConstantPoolMember.h"

class ConstantPoolLinkMember : public ConstantPoolMember {
private:
    uint8_t tag;
    uint16_t nameIndex = 0;
public:
    explicit ConstantPoolLinkMember(uint8_t tag);

    void printState() override;

    void initState(std::ifstream &inputStream) override;
};


#endif //CLASS_PARSER_CPP_CONSTANTPOOLLINKMEMBER_H
