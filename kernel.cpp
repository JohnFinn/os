#include <cstdint>

#include "stringview.hpp"

struct ColorNChar
{
    uint8_t character;
    uint8_t color;
};


ColorNChar* VideoMemory = reinterpret_cast<ColorNChar*>(0x000b8000);


void write_string(StringView string)
{
    size_t idx = 0;
    for (char c : string) {
        VideoMemory[idx].character = c;
        ++idx;
    }
}


extern "C" void kmain(void* multiboot_struct, unsigned int magic_number){
    write_string(STRING_VIEW("hello world, azaza"));
    while (1)
        ;
}
