#ifndef INCLUDE_KINTERRUPTS_H
#define INCLUDE_KINTERRUPTS_H

static unsigned char keyboard_scan_code_to_ascii[256] =
{
    0x0, 0x0, '1', '2', '3', '4', '5', '6',
    '7', '8', '9', '0', '-', '=', 0x0, 0x0,
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',
    'o', 'p', '[', ']', '\n', 0x0, 'a', 's',
    'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
    '\'', '`', 0x0, '\\', 'z', 'x', 'c', 'v',
    'b', 'n', 'm', ',', '.', '/', 0x0, '*',
    0x0, ' ', 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, '7',
    '8', '9', '-', '4', '5', '6', '+', '1',
    '2', '3', '0', '.'
};

struct cpu_state {
    unsigned int eax;
    unsigned int ebx;
    unsigned int ecx;
    unsigned int edx;
    unsigned int ebp;
    unsigned int esi;
    unsigned int edi;
} __attribute__((packed));

struct stack_state {
    unsigned int error_code;
    unsigned int eip;
    unsigned int cs;
    unsigned int eflags;
} __attribute__((packed));

struct idt_desc {
    unsigned short size;
    unsigned int address;
} __attribute__((packed));

struct idt_entry {
    unsigned short offset_lo;
    unsigned short segment_selector;
    
    unsigned char reserved;
    unsigned char pdpl;
    unsigned short offset_hi;
} __attribute__((packed));

void setup_idt(unsigned int address);

void init_entry(int idx, unsigned int address);

void init_idt();

void interrupt_handler_33();

void interrupt_handler(struct cpu_state cpu, unsigned int interrupt, struct stack_state stack);

#endif
