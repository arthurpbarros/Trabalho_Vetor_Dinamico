#include "../include/listInt.h"

void printArray(list_int * a){
    if(a->size > 0){
        list_int_node * no = a->first;
        printf("CAPACITY: %d\nSIZE: %d\n",a->size,a->size);
        int i = 0;
        printf("------------------------\n");
        printf("DADOS DO ARRAY\n");
        while (no != NULL){
            printf("V[%d] = %d\n",i,no->value);
            no = no->next;
            i++;
        }
        printf("------------------------\n");
    }else{
        printf("VETOR NULO\n");
    }
}

list_int * list_create(){
    list_int * lista = (list_int*)malloc(sizeof(list_int));
    lista->size = 0;
    lista->first = 0;
    lista->last = 0;
    return lista;
}

int list_get(list_int * TIPO, int index){
    return 0;
}

unsigned int list_push_back(list_int * TIPO, int i){
    list_int_node * ele = (list_int_node*)malloc(sizeof(list_int_node));
    if(!ele){
        printf("Não foi possível alocar memória pro novo elemento\n");
        return 0;
    }
    ele->value = i;

    
    if(!TIPO->first){
        ele->next = 0;
        ele->prev = 0;
        
        TIPO->first = ele;
        TIPO->last = ele;
        //TIPO->size++;
    }else{
        //printf("%p %d\n",ele,ele->value);
        list_int_node * it = TIPO->last;
        ele->next = 0;
        ele->prev = TIPO->last;
        it->next = ele;
        TIPO->last = ele;
        
    }
    return ++TIPO->size;
    
}

unsigned int list_pop_back(list_int * TIPO){
    if(TIPO->size <= 0){
        printf("O vetor está vazio, não foi possível remover o último elemento!\n");
        return -1;
    }else if(TIPO->size == 1){
        free(TIPO->last);
        TIPO->last = 0;
        TIPO->first = 0;
    }else{
        list_int_node * ultimo = TIPO->last;
        list_int_node * pen = ultimo->prev;
        pen->next = 0;
        TIPO->last = pen;
        free(ultimo);
    }
    return --TIPO->size;
}

int list_find(list_int * TIPO, int element){
    if(TIPO->size <= 0){
        return -1;
    }
    list_int_node * it = TIPO->first;
    int i = 0;
    while(it){
        if(it->value == element){
            return i;
        }
        it = it->next;
        i++;       
    }
    return -1;
}

int list_int_insert_at(list_int * TIPO, int index, int value){
    return 0;
}

int list_int_remove_from(list_int * TIPO, int index){
    return 0;
}

unsigned int list_size(list_int * TIPO){
    return TIPO->size;
}

unsigned int list_capacity(list_int * TIPO){
    return TIPO->size;
}

double list_int_percent_occuped(list_int * TIPO){
    return 1.0;
}

void list_int_destroy(list_int * TIPO){
    
}
