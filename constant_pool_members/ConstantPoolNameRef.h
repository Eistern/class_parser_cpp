#ifndef CLASS_PARSER_CPP_CONSTANTPOOLNAMEREF_H
#define CLASS_PARSER_CPP_CONSTANTPOOLNAMEREF_H

#include "ConstantPoolMember.h"

class ConstantPoolNameRef : public ConstantPoolMember {
private:
    uint8_t tag;
    uint16_t classIndex = 0;
    uint16_t nameAndTypeIndex = 0;
public:
    explicit ConstantPoolNameRef(uint8_t tag);

    void printState() override;

    void printResolved() override;

    void initState(std::ifstream &inputStream) override;
};


#endif //CLASS_PARSER_CPP_CONSTANTPOOLNAMEREF_H
