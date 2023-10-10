/**
  ******************************************************************************
  * @file           : insertsort.h
  * @author         : Kenny
  * @brief          : None
  * @attention      : None
  * @date           : 2023/10/10
  ******************************************************************************
  */


#ifndef SORTS_INSERTSORT_H
#define SORTS_INSERTSORT_H
/**
  * @brief  insert sort for int-type, float-type and string
  * @note   None
  * @param  array:              the array need to be sort
  * @param  numElements:        the number of elements in array
  * @param  elementSize:        the bits of each element in memory
  * @param  cmp:                a function pointer which compares with two elements
  * @retval None
  */
void insertsort(void* array,int numElements,size_t elementSize,int(*cmp)(const void*,const void*));
#endif //SORTS_INSERTSORT_H
