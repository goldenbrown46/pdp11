#include "lib.h"

void halt() {
    printf("\n");
    reg_dump();
    exit(0);
}

void add() {
    w_write(dd.adr, (dd.val + ss.val) & 0xFFFF);
}

void mov() {
    b_write(dd.adr, ss.val & 0xFFFF);
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

void run()
{
    pc = 0x200;
    word w;
    while(1) {
        w = w_read(pc);
        printf("%06o : %06o ", pc, w);
        pc += 2;
        if (w == 0) {
            printf("halt ");
            halt();
        } else if (w == 0)
        printf("\n");
    }
}
