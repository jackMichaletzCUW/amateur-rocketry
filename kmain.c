#include "io.h"
#include "fb.h"
#include "kmemory.h"
#include "kinterrupts.h"
#include "gdt.h"
#include "string.h"
#include "prompt.h"

int main()
{
    gdt_init();
    init_idt();
	clr_scrn();
    
    //checkers(0, 15);
    
    newline();
    writechar(' ');
    writechar(201);
    for(int i = 0; i < 32; i++) { writechar(205); }
    writechar(187); newline();
    writechar(' ');
    writechar(186);
    write(" a m a t e u r  r o c k e t r y ", 32);
    writechar(186);
    newline();
    writechar(' ');
    writechar(200);
    for(int i = 0; i < 32; i++) { writechar(205); }
    writechar(188); newline();
    newline();
    
    memoryInitialize();
    
    promptInitialize("amateur rocketry> ");
    
    //writestr("feep");
    // char** list = stringTokenize("whose toes are those", ' ');
    // writeint((int)(*list));
    // writebytes((char*)list, 20, 4);
    // stringPrintList(list);
    
	return 0;
}
