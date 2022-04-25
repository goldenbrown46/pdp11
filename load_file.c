#include "lib.h"

void load_file(const char * file_name) {
    FILE * f = fopen(file_name, "r"); //читать из файла
    unsigned int N; //адрес_начала_блока
    unsigned int num; //считывать 2 числа
    unsigned int n; // число байт

    while(fscanf(f, "%x%x", &N, &n) == 2) {
        for(int i = 0; i < n; i++) {
            fscanf(f, "%x", &num);
            b_write(N + i, (byte)num);
        }
    }
    fclose(f);
}