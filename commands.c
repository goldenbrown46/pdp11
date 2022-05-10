#include "lib.h"

struct Argument  ss, dd;
word w;
word NN;
word r;

void halt() {
    printf("\n");
    reg_dump();
    exit(0);
}

void add() {
    w_write(dd.adr, (dd.val + ss.val) & 0xFFFF);
}

void mov() {
    w_write(dd.adr, ss.val & 0xFFFF);
}

void movb() {
    b_write(dd.adr, ss.val);
}

void sob() {
    reg[r] = reg[r] - 1;
    if (reg[r] != 0) {
        pc = pc - (2 * NN);
    }
    //printf("%06o ", pc);
}

void clr() {
    w_write(dd.adr, 0);
}

void do_unknown() {
    printf("What is this??!!\n");
    reg_dump();
    exit(1);
}

struct Command cmd[] = {
    {0177777, 0000000, "HALT", halt, NO_PARAMS},
    {0170000, 0010000, "MOV", mov, HAS_SS | HAS_DD},
    {0170000, 0110000, "MOVB", movb, HAS_SS | HAS_DD},
    {0170000, 0060000, "ADD", add, HAS_SS | HAS_DD},
    {0177000, 0077000, "SOB", sob, HAS_R | HAS_N},
    {0177700, 0005000, "CLR", clr, HAS_DD},
    {0000000, 0000000, "UNKNOWN", do_unknown, NO_PARAMS}
};

void run()
{
    pc = 0x200;
    while(1) {
        w = w_read(pc);
        printf("%06o : %06o ", pc, w);
        pc += 2;
        flag.val = w >> 15;
        for(int j = 0; ; j++) {
            if ((w & cmd[j].mask) == cmd[j].opcode) {
                printf("%s ", cmd[j].name);
                if (cmd[j].params & HAS_R) {
                    r = (w >> 6) & 7;
                    printf("R%o ", r);
                }
                if (cmd[j].params & HAS_SS) {
                    ss = get_mode(w >> 6);
                }
                if (cmd[j].params & HAS_DD) {
                    dd = get_mode(w);
                }
                if (cmd[j].params & HAS_N) {
                    NN = (w & 077);
                    printf("%06o", pc - 2 * NN);
                }
                cmd[j].do_command();
                printf("\n");
                //reg_dump();
                break;
            }
        }
        
    }
}
