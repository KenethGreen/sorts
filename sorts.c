/**
  ******************************************************************************
  * @file           : sorts.c
  * @author         : Kenny
  * @brief          : None
  * @attention      : None
  * @date           : 2023/10/10
  ******************************************************************************
  */

#include <string.h>
#include "sorts.h"
#define CMP(x,y)     if((x) == (y))         \
                        return 0;           \
                     else if((x) < (y))     \
                        return -1;          \
                     else                   \
                        return 1;
int cmpInt(const void *a, const void *b) {
    const int * x = (const int*)a;                                                  // 4 bytes each element
    const int * y = (const int*)b;                                                  // 4 bytes each element
    CMP(*x,*y)                                                                      // (*x==*y)?(0):((*x<*y)?(-1):(1))
}

int cmpFloat(const void *a,const void *b)
{
    const float * x = (const float *)a;                                             // 4 bytes each element
    const float * y = (const float *)b;                                             // 4 bytes each element
    CMP(*x,*y)                                                                      // (*x==*y)?(0):((*x<*y)?(-1):(1))
}

int cmpString(const void **a,const void **b)
{
    const char **x = (const char **)a;
    const char **y = (const char **)b;
    return strcmp(*x,*y);
}