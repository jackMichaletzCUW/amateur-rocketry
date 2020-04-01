#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H

char* stringCopy(char* source, int size);
void stringDuplicate(char* source, char* destination);
char* stringCat(char* a, char* b);
void stringAddChar(char* s, char c);
void stringClear(char* target);
void stringRemove(char* target);
int stringSize(char* target);
int stringOccurrences(char* target, char token);
char** stringTokenize(char* string, char token);
void stringPrintList(char** target);

#endif
