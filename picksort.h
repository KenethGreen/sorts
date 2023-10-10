/**
  ******************************************************************************
  * @file           : picksort.h
  * @author         : Kenny
  * @brief          : None
  * @attention      : None
  * @date           : 2023/10/10
  ******************************************************************************
  */


#ifndef SORTS_PICKSORT_H
#define SORTS_PICKSORT_H

void picksort(void *array,int numElements,size_t elementSize,int(*cmp)(const void*,const void*));
#endif //SORTS_PICKSORT_H
