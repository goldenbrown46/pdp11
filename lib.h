#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte ; // 8 bit
typedef unsigned short int word ; // 16 bit
typedef word Adress ; // 64 Kb

extern byte mem[64*1024];
extern word reg[8];

#define pc reg[7]

void b_write (Adress adr, byte b);
byte b_read (Adress adr);
void w_write (Adress adr, word w);
word w_read (Adress adr);

void load_file(const char * file_name);
void mem_dump(Adress start, word n);
void reg_dump();

struct Argument {
    word val;
    word adr;
};
extern struct Argument ss, dd;

extern word w;
extern word NN;

void run();

void halt();
void add();
void mov();
void movb();
void sob();
