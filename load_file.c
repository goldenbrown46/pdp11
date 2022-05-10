#include "lib.h"

void load_file(const char * file_name) {
    FILE * f = fopen(file_name, "r"); //читать из файла
    unsigned int N; //адрес_начала_блока
    unsigned int num; //считывать 2 числа
    unsigned int n; // число байт

    if (f == NULL) {
        perror(file_name);
        exit(1);
    }
    
    while(fscanf(f, "%x%x", &N, &n) == 2) {
        for(unsigned int i = 0; i < n; i++) {
            fscanf(f, "%x", &num);
            b_write(N + i, (byte)num);
        }
    }
    fclose(f);
}

void mem_dump(Adress start, word n) {
    unsigned int i;
    for (i = 0; i < n; i += 2) {
        printf("%06o : %06o\n", ((Adress)(start + i)), w_read((Adress)(start + i)));
    }
}

int main()
{
    load_file("./tests/02_sob_byte/02_sob_byte.pdp.o");
    // mem_dump(0x200, 10);
    run();

    return 0;
}
