global asm_load_gdt
global asm_load_regs

asm_load_gdt:
    lgdt [esp + 4]
    ret

asm_load_regs:
    mov ax, 0x10
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    jmp 0x08:flush_cs

flush_cs:
    ret
