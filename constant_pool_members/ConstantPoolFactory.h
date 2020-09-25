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
#include "ConstantPoolMethodHandle.h"

namespace constant_pool_factory {
    ConstantPoolMember *get(uint8_t tag, std::map<uint16_t, ConstantPoolMember *> *pool) {
        ConstantPoolMember *result;
        switch (tag) {
            case 7:
            case 8:
            case 16:
                result = new ConstantPoolLinkMember(tag);
                break;
            case 9:
            case 10:
            case 11:
            case 12:
            case 18:
                result = new ConstantPoolNameRef(tag);
                break;
            case 1:
                result = new ConstantPoolUtfString();
                break;
            case 3:
                result = new ConstantPoolInteger();
                break;
            case 5:
                result = new ConstantPoolLong();
                break;
            case 4:
                result = new ConstantPoolFloat();
                break;
            case 6:
                result = new ConstantPoolDouble();
                break;
            case 15:
                result = new ConstantPoolMethodHandle();
                break;
            default:
                throw std::exception();
        }
        result->setOwnerPool(pool);
        return result;
    }
}

#endif //CLASS_PARSER_CPP_CONSTANTPOOLFACTORY_H
