#include "io.h"
#include "fb.h"
#include "kmem.h"
#include "kinterrupts.h"
#include "gdt.h"

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
    //write("   dildOS kernel 1.0", 20);
    //newline();
    newline();
    
    /*memoryInitialize();
    
    char* l = yoink(16);
    
    writeint((int)l);
    newline();
    writeint((int)yoink(2)); newline();
    writeint((int)yoink(3)); newline();
    writeint((int)yoink(4)); newline();
    newline();
    
    while(1) {}
    
    return 0;*/
    
    meminit();
    
    /*newline();
    
	char* a;
    
    write("DEALING...", 10);
    newline();
    write("COUNT: ", 7);

	int max = 10000;
	int mp = mp / 2;
    
    char** t = deal(4 * max);

	for(int i = 0; i < max; i++)
	{
            t[i] = deal(5);
        writeupdateint(i);
	}

    newline();
	write("FREEING...", 10);
    newline();
    write("COUNT: ", 7);

	for(int i = 0; i < max; i++)
    {
        if(i % 10 == 0) {
            
            fold(t[i]);
            writeupdateint(i / 10);
        }
    }

    newline();

	write("DEALING...", 10);
    newline();
    write("COUNT: ", 7);

    for(int i = 0; i < (max / 10); i++)
    {
	deal(5);
        writeupdateint(i);
    }*/
    newline();
    newline();
    
    //for(;;) {
     //   asm("hlt");
    //}
    
    
    
	return 0;
}
