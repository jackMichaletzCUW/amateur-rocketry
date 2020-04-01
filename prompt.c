#include "prompt.h"
#include "string.h"
#include "fb.h"

#define P_COL 0xF

char* content;
char* prompt;
int promptSize = 0;
int contentSize = 0;

void promptInput(char input)
{
    if(contentSize < 2000) {
        writeinputchar(input);
        
        //stringAddChar(content, input);
        *(content + contentSize) = input;
        *(content + contentSize + 1) = '\0';
        
        contentSize++;
    }
}

void promptRun()
{
    newline();
    
    if(contentSize != 0) {
        stringPrintList(stringTokenize(content, ' '));
    }
    
    stringClear(content);
    contentSize = 0;

    promptPrint();
}

void promptDelete()
{
    if(contentSize > 0)
    {
        *(content + contentSize) = '\0';
        contentSize--;
        removechar();
    }
}

void promptPrint()
{
    for (int i = 0; i < promptSize; i++) {
        writecolorchar(*(prompt + i), P_COL);
    }
    
    drawblock();
}

void promptInitialize(char* promptString)
{
    content = memoryAllocate(2000);
    promptSize = stringSize(promptString);
    prompt = memoryAllocate(promptSize + 1);
    
    stringDuplicate(promptString, prompt);
    
    promptPrint();
}

