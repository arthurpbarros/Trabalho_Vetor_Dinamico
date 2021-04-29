#include "../include/listInt.h"

void printArray(list_int * a){
    if(a->size > 0){
        list_int_node * no = a->first;
        printf("CAPACITY: %d\nSIZE: %d\n",a->size,a->size);
        int i = 0;
        printf("------------------------\n");
        printf("DADOS DO ARRAY\n");
        while (no){
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
    //Aloca lista vazia na memória,
    list_int * lista = (list_int*)malloc(sizeof(list_int));
    if(!lista){
        printf("Lista não foi alocada na memória por falta de espaço!\n");
        return 0;
    }
    //Inicializa valores da lista vazia
    lista->size = 0;    //Tamanho
    lista->first = 0;   //Primeiro elemento
    lista->last = 0;    //Último elemento
    return lista;       //Retorna o endereço da lista
}

int list_get(list_int * TIPO, int index){
    //Se índice é inválido, retorna -1
    if(index < 0 || index >= TIPO->size){
        return -1;
    }
    int i = 0;
    list_int_node * it = TIPO->first;
    //Itera sobre a lista até o 'index'
    while (i++ < index){
        it = it->next;
    }
    //Retorna o valor do índice
    return it->value;
}

unsigned int list_push_back(list_int * TIPO, int i){
    //Aloca espaço para o novo elemento
    list_int_node * ele = (list_int_node*)malloc(sizeof(list_int_node));
    //Verifica se o espaço foi alocado 
    if(!ele){
        printf("Não foi possível alocar memória pro novo elemento\n");
        return 0;
    }
    //Adiciona valor ao elemento
    ele->value = i;

    //Verifica se a lista é vazia, se for adiciona o elemento
    if(!TIPO->first){
        ele->next = 0;
        ele->prev = 0;
        
        TIPO->first = ele;  //Primeiro e último elemento são iguais
        TIPO->last = ele;
    }else{
        //Adiciona o novo elemento no fim da lista
        list_int_node * it = TIPO->last;    
        ele->next = 0;
        ele->prev = TIPO->last;
        it->next = ele;
        TIPO->last = ele;
        
    }
    //Retorna o novo tamanho
    return ++TIPO->size;
    
}

unsigned int list_pop_back(list_int * TIPO){
    //Verifica se a lista está vazia
    if(TIPO->size <= 0){
        printf("O vetor está vazio, não foi possível remover o último elemento!\n");
        return 0;
    }else if(TIPO->size == 1){  //Se a lista tem um elemento, libera/apaga o único elemento
        free(TIPO->last);
        TIPO->last = 0;
        TIPO->first = 0;
    }else{
        //Remove o último elemento
        list_int_node * ultimo = TIPO->last;
        list_int_node * pen = ultimo->prev;
        pen->next = 0;
        TIPO->last = pen;
        free(ultimo);
    }
    //Retorna o novo tamanho da lista
    return --TIPO->size;
}

int list_find(list_int * TIPO, int element){
    //Verfica se a lista está vazia e então não retorna um índice indeterminado
    if(TIPO->size <= 0){
        return -1;
    }
    list_int_node * it = TIPO->first;
    int i = 0;
    while(it){
        if(it->value == element){
            //Se encontrar o valor na lista, retorna o índice da lista
            return i;
        }
        it = it->next;
        i++;       
    }
    //Retorna -1 depois de percorrer a lista e não encontrar o valor
    return -1;
}

int list_int_insert_at(list_int * TIPO, int index, int value){
    if(index < 0 || index >= TIPO->size){
        printf("Não foi possível inserir o elemento, índice inválido\n");
        return -1;
    }
    if(index == 0){  //lista tem só um elemento, único index válido é 0
        TIPO->first->value = value;  //altera valor do único elemento
    }else if(index == TIPO->size-1){ 
        TIPO->last->value = value;  //altera valor do último elemento
    }else{
        //itera sobre a lista até o índice
        list_int_node * it = TIPO->first;
        int i = 0;
        while(i++ < index){
          it = it->next;
        }
        //altera o valor do elemento do índice
        it->value = value;
    }
    //Retorna o índice
    return index;
}

int list_int_remove_from(list_int * TIPO, int index){
    if(index < 0 || index >= TIPO->size){
        printf("Não foi possível inserir o elemento, índice inválido\n");
        return TIPO->size;
    }
    if(TIPO->size == 1){    //Se tamanho da lista é 1, apaga o último elemento
        free(TIPO);
        TIPO->first = 0;
        TIPO->last = 0;
    }else { //Tamanho >= 2
        list_int_node * it = TIPO->first;
        if(index == TIPO->size-1){  
            /* se indice é o ultimo, a funcao pop back é invocada,
            para otimizar o código*/                             
            return (int)list_pop_back(TIPO);
        }else if(index == 0){    
            TIPO->first = it->next;
            it->next->prev = it->prev;
            free(it);
        }else{
            int i = 0;
            //it = elemento do índice 'index'
            while (i < index){
                it = it->next; 
            }
            it->next->prev = it->prev;
            it->prev->next = it->next;
            free(it);
        }
    }
    //Retorna o novo tamanho da lista
    return --TIPO->size;
}

unsigned int list_size(list_int * TIPO){
    //Retorna o tamanho da lista
    return TIPO->size;
}

unsigned int list_capacity(list_int * TIPO){
    //Retorna a capacidade da lista, que numa lista ligada é igual ao tamanho
    return TIPO->size;
}

double list_int_percent_occuped(list_int * TIPO){
    //Retorna 1.0 pois a lista sempre está ocupada, a menos que esteja vazia.
    return TIPO->size == 0?0.0:1.0;
}

void list_int_destroy(list_int * TIPO){
    //Verifica se o lista é nulo, se sim, libera a lista
    if(TIPO->size == 0){
        list_int * aux = TIPO;
        TIPO = 0;
        free(aux);
        return;
    }
    /*itera sobre a lista de traz para frente, guardando o 
        endereço do último valor e liberando a memória do mesmo*/
    list_int_node * it = TIPO->last;
    while(it){
        list_int_node * del = it;
        it = it->prev;
        TIPO->last = it;
        if(it){
          it->next = 0;
          TIPO->first = 0;
        }
        free(del);
    }
    //Zera atributos
    TIPO->first = 0;
    TIPO->last = 0;
    TIPO->size = 0;
    list_int * old = TIPO;
    //Seta endereço de lista como NULL ou 0
    TIPO = 0;
    //Libera memória
    free(old);
}
