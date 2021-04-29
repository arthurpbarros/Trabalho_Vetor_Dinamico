#include "../include/arrayInt.h"

void printArray(array_int * a){
    if(a){
        printf("INITIAL CAPACITY: %d\nCAPACITY: %d\nSIZE: %d\n",a->i_cap,a->capacity,a->size);
        int i;
        printf("DADOS DO ARRAY\n");
        printf("----------------\n");
        for(i = 0; i < a->size; i++){
            printf("V[%d] = %d\n",i,a->data[i]);
        }
        printf("----------------\n");
    }else{
        printf("VETOR NULO\n");
    }
}

array_int * array_create(unsigned int initial_capacity){
    //Aloca o struct do vetor dinâmico.
    array_int * v = (array_int*)malloc(sizeof(array_int));
    //Verifica se o struct foi alocado dinâmicamente. 
    if (!v){
        printf("Memória insuficiente para alocar vetor dinâmico!\n");
        return 0;
    }
    //Aloca o espaço para os dados(elementos) do vetor dinâmico com capacidade inicial igual ao paramêtro passado.
    v->data = (int*) malloc(initial_capacity*sizeof(int));
    //Verifica se os espaço inicial destinado aos elementos do vetor foi alocado.
    if (!v->data){
        printf("Memória insuficiente para alocar os dados do vetor dinâmico!\n");
        return 0;
    }
    //Inicializa os demais atributos do vetor dinâmico.
    v->size = 0;
    v->capacity = initial_capacity;
    v->i_cap = initial_capacity;
    return v;
}

int array_get(array_int * TIPO, int index){
    //Verifica se índice é valido, entre 0 e tamanho-1 do vetor.
    if(index < 0 || index >= TIPO->size){
        return -1;
    }
    return TIPO->data[index];
}

unsigned int array_push_back(array_int * TIPO, int i){
    //Se o vetor estiver cheio, a capacidade deve ser aumentada
    if(TIPO->size == TIPO->capacity){
        int * new_data;
        if(TIPO->i_cap == 2){
            new_data = (int *)realloc(TIPO->data,TIPO->capacity<<1);
            TIPO->capacity = TIPO->capacity<<1;
        }else if(TIPO->i_cap == 10000){
            new_data = (int *)realloc(TIPO->data,TIPO->capacity+10000);
            TIPO->capacity = TIPO->capacity+10000;
        }else{
            new_data = (int *)realloc(TIPO->data,TIPO->capacity+10);
            TIPO->capacity = TIPO->capacity+10;
        }
        if(!new_data){
            printf("Memória insuficiente para adicionar o elemento '%d' no vetor dinâmico.\n",i);
            return TIPO->size;
        }
    }
    TIPO->data[TIPO->size++] = i;
    return TIPO->size;
}

unsigned int array_pop_back(array_int * TIPO){
    if(TIPO->size <= 0){
        return 0;
    }
    int * new_data = (int*)malloc(TIPO->capacity*sizeof(int));
    //Copia os elementos do vetor que são anteriores ao último índice para outro vetor;  
    int i;
    for(i=0;i < TIPO->size-1;i++){
        new_data[i] = TIPO->data[i];
    }
    //Libera memória dos elementos originais, isto é,  apaga todos.
    free(TIPO->data);
    TIPO->data = new_data;
    //Diminui o tamanho do vetor e o retorna em sequência
    return --TIPO->size;
}

int array_find(array_int * TIPO, int element){
    //Se a lista está vazia, retorne -1
    if(TIPO->size <= 0){
        return -1;
    }
    int i;
    for(int i = 0; i < TIPO->size;i++){
        if(TIPO->data[i] == element){
            return i;   //Retorna o menor índice, onde encontra o elemento no array
        }
    }
    //Não encontrou o elemento no array, retorna -1
    return -1; 
}

int array_insert_at(array_int * TIPO, int index, int value){
    //Indice inválido
    if(index < 0 || index >= TIPO->size){
        return -1;
    }
    //Se o índice for válido, insere o valor no vetor
    TIPO->data[index] = value;
    return index;   //retorna índice do elemento inserido
}

int array_remove_from(array_int * TIPO, int index){
    //Verifica se o índice é inválido
    if(index < 0 || index >= TIPO->size){
        return TIPO->size;
    }
    //Indice válido, desloca elementos a direita de index para a esquerda, 
    //substituindo o valor de index pelo próximo
    int i;
    for(i = index+1;i < TIPO->size;i++){
        TIPO->data[i-1] = TIPO->data[i];
    }
    TIPO->size--; //Reduz tamanho do vetor em 1
    TIPO->data[TIPO->size] = -1; //Inutitiliza valor do último elemento
    return TIPO->size; //Returna o novo tamanho
}

unsigned int array_size(array_int * TIPO){
    //Retorna tamanho
    return TIPO->size;
}

unsigned int array_capacity(array_int * TIPO){
    //Retorna capacidade
    return TIPO->capacity;
}

double array_percent_occuped(array_int * TIPO){
    //Retorna percentual ocupado do array, seu tamanho/capacidade entre 0 a 1
    return (1.0*TIPO->size) / TIPO->capacity;
}

//TIPO tem o endereço do vetor
//end pointer recebe o endereco de TIPO
void array_destroy(array_int * TIPO){
    array_int ** old = &(TIPO);
    TIPO = 0;
    free (*old);
}
