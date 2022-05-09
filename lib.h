#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte ; // 8 bit
typedef unsigned short int word ; // 16 bit
typedef word Adress ; // 64 Kb

extern byte mem[];
extern word reg[];
extern word w;
extern word r;
extern word NN;

#define NO_PARAMS 0
#define HAS_DD 1
#define HAS_SS (1<<1)
#define HAS_R (1<<2)
#define HAS_N (1<<3)
#define HAS_XX (1<<4)
#define HAS_R6 (1<<5)

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
extern struct Argument flag;

struct Argument get_mode(word w);

void run();

void halt();
void add();
void mov();
void movb();
void sob();
void clr();
void do_unknown();


struct Command
{
    word mask;
    word opcode;
    char * name;
    void (*do_command) ();
    char params;
};

extern struct Command cmd[];
