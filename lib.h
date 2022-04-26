#include <stdio.h>

typedef unsigned char byte ; // 8 bit
typedef unsigned short int word ; // 16 bit
typedef word Adress ; // 64 Kb

byte mem[64*1024];
word reg[8];
word pc = reg[7];

void b_write (Adress adr, byte b);
byte b_read (Adress adr);
void w_write (Adress adr, word w);
word w_read (Adress adr);

void load_file(const char * file_name);
void mem_dump(Adress start, word n);

struct Argument {
    word val;
    word adr;
} ss, dd;

word w = 0;
word NN = 0;

void halt();
void add();
void mov();
void movb();
void sob();
