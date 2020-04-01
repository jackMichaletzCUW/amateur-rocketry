#include "fb.h"
#include "pic.h"
#include "kinterrupts.h"
#include "prompt.h"

#define KBD_DATA_PORT 0x60

struct idt_desc idt;
struct idt_entry idt_entries[256];

void init_entry(int idx, unsigned int address)
{
    idt_entries[idx].offset_hi = (address >> 16) & 0xFFFF;
    idt_entries[idx].offset_lo = address & 0xFFFF;
    
    idt_entries[idx].segment_selector = 0x0008;
    
    idt_entries[idx].reserved = 0x00;
    idt_entries[idx].pdpl = (0x01 << 7) | (0x00 << 6) | (0x00 << 5) |
    (0xE);
}

void init_idt()
{
    init_entry(33, (unsigned int)interrupt_handler_33);
    
    idt.size = sizeof(struct idt_entry) * 256;
    idt.address = (int)&idt_entries;
    
    setup_idt((int) &idt);
    
    pic_remap(0x20, 0x28);
}

void interrupt_handler(__attribute__((unused)) struct cpu_state cpu, unsigned int interrupt, __attribute__((unused)) struct stack_state stack)
{
    if(interrupt == 33) // keys
    {
        unsigned char scan_code = inb(KBD_DATA_PORT);
        
        char letter = keyboard_scan_code_to_ascii[scan_code];
        
        if(!(scan_code >> 7))
        {
            if(scan_code == 0x1C)
            {
                promptRun();
            }
            else if(scan_code == 0x0E)
            {
                promptDelete();
            }
            else
            {
                promptInput(letter);
            }
        }
        
        pic_acknowledge(interrupt);
    }
}
