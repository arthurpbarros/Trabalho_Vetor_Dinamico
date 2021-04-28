/*
 * ANSI C dinamic array of int values library
 *
 * Author:
 * Date:
 *
 */
#ifndef list_int_H
#define list_int_H
#include <stdlib.h>
#include <stdio.h>
/**
 * Type: list_int
 * Description: a list_int is a pointer to a type that
 * stores the dynamic array data.
 *
 */
typedef struct list_int_node{
    int value;
    struct list_int_node *prev;
    struct list_int_node *next;
} list_int_node;

typedef struct list_int {
    list_int_node *first;
    list_int_node *last;
    unsigned int size;
} list_int;
void printArray(list_int * a);
/**
 * Function: list_int * list_int_init();
 *
 * Description: Creates and inititialize a dynamic array list of
integers.
 *
 * Return: A pointer to list_int type, the dynamic array
implementation
 *
 */
list_int * list_create();
/**
 * Function: int list_int_get(list_int * TIPO, int index);
 *
 * Description: Gets the element at index 'index'.
 *
 * Return: The element located at index i.
 * The value is undeterminated if index is not in the range
[0..size-1]
 *
 */
int list_get(list_int * TIPO, int index);
/**
 * Function: unsigned int list_int_push_back(list_int * TIPO, int i);
 *
 * Description: Add integer value 'i' to the end of the 'TIPO' dynamic
array.
 *
 * Return: The number of elements stored in 'TIPO' AFTER inserting
'i'.
 *
 */
unsigned int list_push_back(list_int * TIPO, int i);
/**
 * Function: unsigned int list_int_pop_back(list_int * TIPO);
 *
 * Description: Removes the last element of the dynamic array
 * referenced (pointed) by 'TIPO'.
 *
 * Return: The number of elements after deletion.
 *
 */
unsigned int list_pop_back(list_int * TIPO);
/**
 * Function: unsigned int list_int_size(list_int * TIPO);
 *
 * Description: Computes the number of int elements stored in 'TIPO'.
 *
 * Return: The number of integer values stored in 'TIPO'.
 *
 */
unsigned int list_int_size(list_int * TIPO);
/*
∗ Function: int TIPO_find(TIPO_int ∗ TIPO, int element);
∗
∗ Description: Gets the index of element 'element'.
∗
∗ Return: The index of element 'element' if element is in the range [0..size−1].
∗
*/
int list_find(list_int * TIPO, int element);
/**
 * Function: int TIPO_insert_at(TIPO_int * TIPO, int index, int value);
 *
 * Description: Inserts int value 'value' at index 'index'. 'index' must
 *              be a valid index, between 0 and 'TIPO_size'-1.
 *
 * Return: the value index, if insertion ok or -1 if the insertion could
 *         not be done.
 *
 */
int list_int_insert_at(list_int * TIPO, int index, int value);
/**
 * Function: TIPO_remove_from(TIPO_int * TIPO, int index);
 *
 * Description: Removes the value at index 'index'. 'index' must
 *              be a valid index, between 0 and 'TIPO_size'-1.
 *
 * Return: The size of the new TIPO_int.
 *
 */
int list_int_remove_from(list_int * TIPO, int index);
/**
 * Function: unsigned int TIPO_capacity(TIPO_int * TIPO);
 *
 * Description: Computes the TIPO_int TIPO capacity.
 *
 * Return: The capicity of the 'TIPO' TIPO_int.
 *
 */
unsigned int list_int_capacity(list_int * TIPO);
/**
 * Function: unsigned int TIPO_percent_occuped(TIPO_int * TIPO);
 *
 * Description: Check the TIPO_int 'TIPO' occupation, in percent.
 *
 * Return: A double, from 0 to 1 with the occupation rate of 'TIPO'.
 *
 */
double list_int_percent_occuped(list_int * TIPO);
/**
 * Function: void TIPO_destroy(TIPO_int * TIPO);
 *
 * Description: Relese memory used by the 'TIPO' reference.
 * Invalidate memory area too.
 *
 */
void list_int_destroy(list_int * TIPO);

#endif