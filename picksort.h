/**
  ******************************************************************************
  * @file           : picksort.h
  * @author         : Kenny
  * @brief          : declare quicksort function
  * @attention      : None
  * @date           : 2023/10/10
  ******************************************************************************
  */


#ifndef SORTS_PICKSORT_H
#define SORTS_PICKSORT_H
/**
  * @brief  quick sort for int-type, float-type and string
  * @note   None
  * @param  array:              the array need to be sort
  * @param  numElements:        the number of elements in array
  * @param  elementSize:        the bits of each element in memory
  * @param  cmp:                a function pointer which compares with two elements
  * @retval None
  */
void picksort(void *array,int numElements,size_t elementSize,int(*cmp)(const void*,const void*));
#endif //SORTS_PICKSORT_H
