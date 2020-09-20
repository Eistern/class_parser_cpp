#include "endian_fix.h"

void toBigEndian(char *input_buffer, size_t buffer_size) {
    if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) {
        return;
    }
    char temp;
    for (int i = 0; i < buffer_size / 2; i++) {
        temp = input_buffer[i];
        input_buffer[i] = input_buffer[buffer_size - 1 - i];
        input_buffer[buffer_size - 1 - i] = temp;
    }
}
