#include "string.h"
#include "kmemory.h"

char* stringCopy(char* source, int size)
{
    char* destination = memoryAllocate(size + 1);
    
    for (int i = 0; i<size; i++) {
        *(destination + i) = *(source + i);
    }
    
    *(destination + size) = '\0';
    
    return destination;
}

void stringDuplicate(char* source, char* destination)
{
    for (int i = 0; i < stringSize(source) + 1; i++) {
        *(destination + i) = *(source + i);
    }
}

char* stringCat(char* a, char* b)
{
    int aSize = stringSize(a);
    int bSize = stringSize(b);
    
    int destinationSize = (aSize + bSize) + 1;
    
    char* destination = memoryAllocate(destinationSize);
    
    for (int i = 0; i< aSize; i++) {
        *(destination + i) = *(a + i);
    }
    
    for (int i = 0; i<(bSize + 1); i++) {
        *(destination + aSize + i) = *(b + i);
    }
    
    return destination;
}

void stringAddChar(char* s, char c)
{
    int size = stringSize(s);
    
    *(s + size) = c;
    *(s + size + 1) = '\0';
}

void stringRemove(char* target)
{
    memoryFree(target, stringSize(target) + 1);
}

// counts number of chars, not including end of string character
int stringSize(char* target)
{
    int count = 0;
    
    while (*target != '\0') {
        count++;
        target++;
    }
    
    return count;
}

int stringOccurrences(char* target, char token)
{
    int rv = 0;
    
    for (int i = 0; i<stringSize(target); i++) {
        if (*(target + i) == token) {
            rv++;
        }
    }
    
    return rv;
}

char** stringTokenize(char* string, char token)
{
    int numberOfTokens = (stringOccurrences(string, token) + 1);
    
    int sizeOfString = stringSize(string);
    
    // allocating an additional byte for null character
    char** list = memoryAllocate((numberOfTokens + 1) * 4);
    
    for (int i = 0; i<numberOfTokens; i++) {
        char* tokenPointer = string;
        
        int tokenOccurrences = 0;
        
        while (tokenOccurrences != i) {
            tokenPointer++;
            
            if (*tokenPointer == token) {
                tokenOccurrences++;
            }
        }
        
        if (tokenOccurrences != 0) {
            tokenPointer++;
        }
        
        // now token pointer points to start of token
        int tokenSize = 0;
        
        if (i == (numberOfTokens - 1)) {
            tokenSize = sizeOfString - ((int)tokenPointer - (int)string);
        } else {
            while (*(tokenPointer + tokenSize) != token) {
                tokenSize++;
            }
        }
        
        char* tokenString = stringCopy(tokenPointer, tokenSize);
                
        *(list + i) = tokenString;
    }
    
    *(list + numberOfTokens) = (char*)0x0;
    
    return list;
}

void stringPrintList(char** target)
{
    int listSize = 0;
    
    while (*(target + listSize) != 0x0) {
        listSize++;
    }
    
    for (int i = 0; i < listSize; i++) {
        writestr(*(target + i));
        
        if (i != (listSize - 1)) {
            write(",", 1);
        }
    }
    
    newline();
}

void stringClear(char* target)
{
    for (int i = 1; i<stringSize(target); i++) {
        *(target+i) = ' ';
    }
    
    *target = '\0';
}
