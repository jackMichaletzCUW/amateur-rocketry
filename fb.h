#ifndef INCLUDE_FB_H
#define INCLUDE_FB_H

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);
void fb_move_cursor(unsigned short pos);
void clr_scrn();
void write(char* str, unsigned int len);
void writeint(int i);
void writestr(char* target);
void newline();
void scroll();
void drawblock();
void checkers(char c1, char c2);
void writebytes(char* start, int count, int columns);
void writebyte(char byte);
void writeupdateint(int i);
void writechar(char c);
void writeinputchar(char c);
void writecolorchar(char c, unsigned int color);
void removechar();

#endif
