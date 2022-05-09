#include "lib.h"

word w = 0;
word NN = 0;
int N, R;

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
    b_write(dd.adr, ss.val & 0xFF);
}

void sob() {
    reg[w] = reg[w] - 1;
    if (reg[w] != 0) {
        pc = pc - (2 * NN);
    }
    printf("%06o ", pc);
}

void do_unknown() {
    printf("What is this??!!\n");
    reg_dump();
}

struct Command command_list[] = {
    {0177777, 0000000, "HALT", halt, NO_PARAMS},
    {0170000, 0010000, "MOV", mov, HAS_SS | HAS_DD},
    {0170000, 0110000, "MOVB", movb, HAS_SS | HAS_DD},
    {0170000, 0060000, "ADD", add, HAS_SS | HAS_DD},
    {0177000, 0077000, "SOB", sob, HAS_R | HAS_N},
    {0170000, 0000000, "UNKNOWN", do_unknown, NO_PARAMS}
};

void run()
{
    pc = 0x200;
    while(1) {
        w = w_read(pc);
        printf("%06o : %06o ", pc, w);
        pc += 2;
        for(int j = 0; ; j++) {
            if ((w & command_list[j].mask) == command_list[j].opcode) {
                printf("%s ", command_list[j].name);
                if (command_list[j].params & HAS_N) {
                    N = (w >> 6) & 7;
                    printf("R%o ", N);
                }
                if (command_list[j].params & HAS_SS) {
                    ss = get_mode(w >> 6);
                }
                if (command_list[j].params & HAS_DD) {
                    dd = get_mode(w);
                }
                if (command_list[j].params & HAS_R) {
                    R = (w & 077);
                    printf("%06o", pc - 2 * R);
                }
                command_list[j].do_command();
                break;
            }
        }
        printf("\n");
    }
}
