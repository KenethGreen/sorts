/**
  ******************************************************************************
  * @file           : mergesort.h
  * @author         : Kenny
  * @brief          : declare mergesort function
  * @attention      : None
  * @date           : 2023/10/11
  ******************************************************************************
  */


#ifndef SORTS_MERGESORT_H
#define SORTS_MERGESORT_H
/**
  * @brief  merge two ordered blocks into a new ordered block
  * @note   None
  * @param  array:          a pointer pointing at the address which contains data but don`t know what type is it
  * @param  start:          the start index of front-block
  * @param  mid:            the end index of front-block
  * @param  end:            the end index of next-block
  * @param  elementSize:    also byte size of data/element data-type
  * @param  cmp:            a function pointer pointing at the function comparing 2 this data-type elements
  * @retval None
  */
void merge(void *array,int start,int mid,int end,size_t elementSize,int(*cmp)(const void*,const void*));

/**
  * @brief  merge sort for elements stored in address which pointed at by the pointer array
  * @note   None
  * @param  array:          a pointer pointing at the address which contains elements that need to be sort
  * @param  numElement:     the number of elements stored in this array
  * @param  elementSize:    also byte size of data/element data-type
  * @param  cmp:            a function pointer pointing at the function comparing 2 this data-type elements
  * @retval None
  */
void mergesort(void *array,int numElement,size_t elementSize,int(*cmp)(const void*, const void*));
#endif //SORTS_MERGESORT_H
