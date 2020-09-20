#include <iostream>
#include "constant_pool_members/ConstantPoolFactory.h"
#include "endian_fix.h"

#define MAGIC_CLASS (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ ? 0xCAFEBABE : 0xBEBAFECA)

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./class_parser <path/to/classfile>";
        return 1;
    }

    std::ifstream input(argv[1], std::ios::binary);
    if (!input.is_open()) {
        std::cerr << "Could not open file";
        return 2;
    }

    uint32_t magic;
    input.read(reinterpret_cast<char *>(&magic), sizeof(magic));
    if (magic != MAGIC_CLASS) {
        std::cerr << "Not a class file";
        return 3;
    }

    uint16_t minor, major;
    input.read(reinterpret_cast<char *>(&minor), sizeof(minor));
    toBigEndian(reinterpret_cast<char *>(&minor), sizeof(minor));
    input.read(reinterpret_cast<char *>(&major), sizeof(major));
    toBigEndian(reinterpret_cast<char *>(&major), sizeof(major));
    std::cout << "Class file format version: Minor: " << minor << " Major: " << major << std::endl;

    uint16_t constant_pool_size;
    input.read(reinterpret_cast<char *>(&constant_pool_size), sizeof(constant_pool_size));
    toBigEndian(reinterpret_cast<char *>(&constant_pool_size), sizeof(constant_pool_size));

    uint8_t tag;
    for (int i = 0; i < constant_pool_size - 1; i++) {
        input.read(reinterpret_cast<char *>(&tag), sizeof(tag));
        if (tag == 6 || tag == 5) {
            i++;
        }
        ConstantPoolMember *member = constant_pool_factory::get(tag);
        member->initState(input);
        std::cout << i + 1 << " ";
        member->printState();
        delete member;
    }

    input.close();
    return 0;
}