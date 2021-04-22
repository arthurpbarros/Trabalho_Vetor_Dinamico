#include "../include/arrayInt.h"
#include <stdio.h>

int main(void) {
    array_int * a = array_create(2);
    printf("%d\n",array_push_back(a,-5));
    printf("%d\n",array_push_back(a,-4));
    printf("%d\n",array_push_back(a,-78));
    printf("%d\n",array_push_back(a,-45));
    printf("%d\n",array_pop_back(a));
    printf("%d\n",array_pop_back(a));
    printf("%d\n",array_pop_back(a));
    printf("%d\n",array_pop_back(a));
    printArray(a);
    array_push_back(a, 30);
    array_push_back(a, 12);
    array_push_back(a, 24);
    array_push_back(a, 36);
    printArray(a);
    printf("%u\n",array_size(a));
    printf("%.2lf\n",array_percent_occuped(a));
    a = array_destroy(a);
    //a = NULL;
    printf("%p\n",a);
}