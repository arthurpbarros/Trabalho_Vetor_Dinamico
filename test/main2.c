#include "../include/listInt.h"
#include <stdio.h>

int main(void) {
    list_int * l = list_create(l);
    list_push_back(l,6);
    list_push_back(l,3);
    list_push_back(l,-9);
    list_pop_back(l);
    list_pop_back(l);
    list_pop_back(l);
    list_push_back(l,5);
    list_push_back(l,825);
    list_push_back(l,320);
    printf("%d\n",list_find(l,320));
    printArray(l);
}
