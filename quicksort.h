/**
  ******************************************************************************
  * @file           : quicksort.h
  * @author         : Kenny
  * @brief          : declare quicksort function
  * @attention      : None
  * @date           : 2023/10/10
  ******************************************************************************
  */


#ifndef SORTS_QUICKSORT_H
#define SORTS_QUICKSORT_H
/**
  * @brief  quick sort for int, float and string
  * @note   None
  * @param  array:              the array need to be sort
  * @param  numElements:        the number of elements in array
  * @param  elementSize:        byte-size of elements
  * @param  cmp:                compare function
  * @retval None
  */
void quicksort(void *array,int numElements,size_t elementSize,int(*cmp)(const void*,const void*));
#endif //SORTS_QUICKSORT_H
