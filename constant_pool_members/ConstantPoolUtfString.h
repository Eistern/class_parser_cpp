#ifndef CLASS_PARSER_CPP_CONSTANTPOOLUTFSTRING_H
#define CLASS_PARSER_CPP_CONSTANTPOOLUTFSTRING_H

#include "ConstantPoolMember.h"

class ConstantPoolUtfString : public ConstantPoolMember {
private:
    uint16_t length = 0;
    char *data = nullptr;
public:
    void initState(std::ifstream &inputStream) override;

    void printState() override;

    ~ConstantPoolUtfString();
};


#endif //CLASS_PARSER_CPP_CONSTANTPOOLUTFSTRING_H
