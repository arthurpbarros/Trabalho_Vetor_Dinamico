/*
 * ANSI C dinamic array of int values library
 *
 * Author:
 * Date:
 *
 */
#ifndef array_int_H
#define array_int_H
#include <stdlib.h>
#include <stdio.h>
/**
 * Type: array_int
 * Description: a array_int is a pointer to a type that
 * stores the dynamic array data.
 *
 */
typedef struct array_int {
    int * data;
    unsigned int capacity;
    unsigned int size;
    unsigned int i_cap;
} array_int;
void printArray(array_int * a);
/**
 * Function: array_int * array_init();
 *
 * Description: Creates and inititialize a dynamic array list of
integers.
 *
 * Return: A pointer to array_int type, the dynamic array
implementation
 *
 */
array_int * array_create(unsigned int initial_capacity);
/**
 * Function: int array_get(array_int * TIPO, int index);
 *
 * Description: Gets the element at index 'index'.
 *
 * Return: The element located at index i.
 * The value is undeterminated if index is not in the range
[0..size-1]
 *
 */
int array_get(array_int * TIPO, int index);
/**
 * Function: unsigned int array_push_back(array_int * TIPO, int i);
 *
 * Description: Add integer value 'i' to the end of the 'TIPO' dynamic
array.
 *
 * Return: The number of elements stored in 'TIPO' AFTER inserting
'i'.
 *
 */
unsigned int array_push_back(array_int * TIPO, int i);
/**
 * Function: unsigned int array_pop_back(array_int * TIPO);
 *
 * Description: Removes the last element of the dynamic array
 * referenced (pointed) by 'TIPO'.
 *
 * Return: The number of elements after deletion.
 *
 */
unsigned int array_pop_back(array_int * TIPO);
/**
 * Function: unsigned int array_size(array_int * TIPO);
 *
 * Description: Computes the number of int elements stored in 'TIPO'.
 *
 * Return: The number of integer values stored in 'TIPO'.
 *
 */
unsigned int array_size(array_int * TIPO);
/**
 * Function: unsigned int TIPO_capacity(TIPO_int * TIPO);
 *
 * Description: Computes the TIPO_int TIPO capacity.
 *
 * Return: The capicity of the 'TIPO' TIPO_int.
 *
 */
unsigned int array_capacity(array_int * TIPO);
/**
 * Function: unsigned int TIPO_percent_occuped(TIPO_int * TIPO);
 *
 * Description: Check the TIPO_int 'TIPO' occupation, in percent.
 *
 * Return: A double, from 0 to 1 with the occupation rate of 'TIPO'.
 *
 */
double array_percent_occuped(array_int * TIPO);
/**
 * Function: void TIPO_destroy(TIPO_int * TIPO);
 *
 * Description: Relese memory used by the 'TIPO' reference.
 * Invalidate memory area too.
 *
 */
void array_destroy(array_int * TIPO);

#endif
