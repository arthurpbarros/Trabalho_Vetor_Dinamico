#include "../include/listInt.h"
#include <stdio.h>

int main(void) {
    list_int * l = list_create(l);
    list_push_back(l,6);
    list_push_back(l,3);
    list_push_back(l,-9);
    printArray(l);
    list_int_destroy(l);
    printArray(l);
}
