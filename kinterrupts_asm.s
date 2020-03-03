extern interrupt_handler

global interrupt_handler_33
interrupt_handler_33:
    push    dword 0
    push    dword 33                    ; push the interrupt number
    jmp     common_interrupt_handler    ; jump to the common handler

common_interrupt_handler:               ; the common parts of the generic interrupt handler
    ; save the registers
    push    eax
    push    ebx
    push    ecx
    push    edx
    push    ebp
    push    esi
    push    edi

    ; call the C function
    call    interrupt_handler

    ; restore the registers
    pop     edi
    pop     esi
    pop     ebp
    pop     edx
    pop     ecx
    pop     ebx
    pop     eax

    ; restore the esp
    add     esp, 8

    ; return to the code that got interrupted
    iret
