#include "gdt.h"

#define SEGMENT_COUNT 3
#define LIMIT 0xFFFFF

const unsigned char code_axb = 0x9A;
const unsigned char data_axb = 0x92;

struct gdt_entry gdt[SEGMENT_COUNT];

void gdt_make_entry(int index, unsigned int address, unsigned char ax_byte)
{
    gdt[index].base_lo = address & 0xFFFF;
    gdt[index].limit_lo = LIMIT & 0xFFFF;
    
    gdt[index].base_mid = (address >> 16) & 0xFF;
    gdt[index].flags_limit = (LIMIT >> 16) & 0xF;
    gdt[index].flags_limit |= (0x0C << 4) & 0xF0;
    gdt[index].access_byte = ax_byte;
    
    gdt[index].base_hi = (address >> 24) & 0xFF;
}

void gdt_init()
{
    gdt[0].base_hi = 0;
    gdt[0].limit_lo = 0;
    gdt[0].base_mid = 0;
    gdt[0].flags_limit = 0;
    gdt[0].access_byte = 0;
    gdt[0].base_lo = 0;
    
    struct gdt_desc* gdtptr = (struct gdt_desc*)gdt;
    gdtptr->size = (sizeof(struct gdt_entry) * SEGMENT_COUNT) - 1;
    gdtptr->offset = (unsigned int)gdt;
    
    gdt_make_entry(1, 0x0, code_axb);
    gdt_make_entry(2, 0x0, data_axb);
    
    asm_load_gdt(*gdtptr);
    asm_load_regs();
}
