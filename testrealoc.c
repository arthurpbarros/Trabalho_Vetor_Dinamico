#include <stdio.h>
#include "stdlib.h"
void print (int v[],int n){
    int i;
    for(i = 0;i<n;i++){
        printf("%d\n",v[i]);
    }
}
int main(){
    int * v = (int*)malloc(5*sizeof(int));
    int i;
    for(int i = 0; i < 5;i++){
        v[i] = 10*i;
    }
    print(v,5);
    int * c = (int*) malloc(3*sizeof(int));
    c = realloc(v,3*sizeof(int));
    
    print(c,4);
    free(v);
    print(c,4);
    return 0;
}