/**
  ******************************************************************************
  * @file           : bubblesort.h
  * @author         : Kenny
  * @brief          : None
  * @attention      : None
  * @date           : 2023/10/9
  ******************************************************************************
  */


#ifndef SORTS_BUBBLESORT_H
#define SORTS_BUBBLESORT_H
/**
  * @brief  bubble sort for int-type, float-type and string
  * @note   None
  * @param  array:              the array need to be sort
  * @param  numElements:        the number of elements in array
  * @param  elementSize:        the bits of each element in memory
  * @param  cmp:                a function pointer which compares with two elements
  * @retval None
  */
void bubblesort(void *array,int numElements,size_t elementSize,int(*cmp)(const void*,const void*));

int cmpInt(const void* a,const void *b);                // compare with int
int cmpFloat(const void* a,const void *b);              // compare with float
int cmpString(const void** a,const void** b);           // compare with string
#endif //SORTS_BUBBLESORT_H
