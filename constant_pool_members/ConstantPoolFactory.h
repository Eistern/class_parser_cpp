#ifndef CLASS_PARSER_CPP_CONSTANTPOOLFACTORY_H
#define CLASS_PARSER_CPP_CONSTANTPOOLFACTORY_H

#include "ConstantPoolMember.h"
#include "ConstantPoolLinkMember.h"
#include "ConstantPoolNameRef.h"
#include "ConstantPoolUtfString.h"
#include "ConstantPoolInteger.h"
#include "ConstantPoolLong.h"
#include "ConstantPoolFloat.h"
#include "ConstantPoolDouble.h"

namespace constant_pool_factory {
    ConstantPoolMember *get(uint8_t tag) {
        switch (tag) {
            case 7:
            case 8:
            case 16:
                return new ConstantPoolLinkMember(tag);
            case 9:
            case 10:
            case 11:
            case 12:
            case 18:
                return new ConstantPoolNameRef(tag);
            case 1:
                return new ConstantPoolUtfString();
            case 3:
                return new ConstantPoolInteger();
            case 5:
                return new ConstantPoolLong();
            case 4:
                return new ConstantPoolFloat();
            case 6:
                return new ConstantPoolDouble();
            default:
                throw std::exception();
        }
    }
}

#endif //CLASS_PARSER_CPP_CONSTANTPOOLFACTORY_H
