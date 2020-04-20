global outb

outb:
    mov al, [esp + 8]
    mov dx, [esp + 4]
    out dx, al
    ret

global inb

inb:
    mov dx, [esp + 4]
    in al, dx
    ret

global toggleBlinking

toggleBlinking:
    mov dx, 0x03DA
    in al, dx
    mov al, 0x30
    mov dx, 0x03C0
    out dx, al
    mov dx, 0x03C1
    in al, dx
    xor al, 0x08
    mov dx, 0x03C0
    out dx, al
