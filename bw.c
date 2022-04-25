#include "lib.h"

void b_write (Adress adr, byte b) {
// пишем байт b по адресу adr
    mem[adr] = b;
}
byte b_read (Adress adr) {
// читаем байт по адресу adr
    return mem[adr];
}
void w_write (Adress adr, word w) {
//пишем слово w по адресу adr
    mem[adr] = (byte)(w);
    mem[adr + 1] = (byte)(w >> 8);
}
word w_read (Adress adr) {
// читаем слово по адресу adr
    word w = ((word)mem[adr + 1]) << 8;
    w = w | mem[adr];
    return w;
}