#include "lib.h"

void halt() {
    printf("\n");
    mem_dump(01000, 0x0c);
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