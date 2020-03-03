global setup_idt

setup_idt:
    mov     eax, [esp+4]
    lidt    [eax]
    ret
