#ifndef INCLUDE_GDT_H
#define INCLUDE_GDT_H

struct gdt_entry {
    unsigned short limit_lo;
    unsigned short base_lo;
    
    unsigned char base_mid;
    unsigned char access_byte;
    
    unsigned char flags_limit;
    unsigned char base_hi;
} __attribute__((packed));

struct gdt_desc {
    unsigned short size;
    unsigned int offset;
} __attribute__((packed));

void gdt_init();

void gdt_make_entry(int index, unsigned int address, unsigned char ax_byte);

void asm_load_gdt(struct gdt_desc gdtdef);
void asm_load_regs();

#endif
