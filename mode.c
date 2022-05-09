#include "lib.h"

struct Argument get_mode(word w) {
    struct Argument res;
    int n = w & 7;
    int mode = (w >> 3) & 7;
    switch(mode) {
        case 0: //Rn
            res.adr = n;
            res.val = reg[n];
            printf("R%d ", n);
            break;
        case 1: //(Rn)
            res.adr = reg[n];
            res.val = w_read(res.adr);
            printf("(R%d) ", n);
            break;
        case 2: //(Rn)+
            res.adr = reg[n];
            //res.adr = w_read(res.adr);
            res.val = w_read(res.adr);
            if (n < 6) {
                reg[n] += 1;
            } else {
                reg[n] += 2;
            }
            if (n == 7) {
                printf("#%06o ", res.val);
            }
            break;
        default:
            fprintf(stderr, "Mode %o NOT IMPLEMENTED YET\n", mode);
            exit(1);
    }
    return res;
}

