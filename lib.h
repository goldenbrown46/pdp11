#include <stdio.h>

typedef unsigned char byte ; // 8 bit
typedef unsigned short int word ; // 16 bit
typedef word Adress ; // 64 Kb

byte mem[64*1024];

void b_write (Adress adr, byte b);
byte b_read (Adress adr);
void w_write (Adress adr, word w);
word w_read (Adress adr);

void load_file(const char * file_name);