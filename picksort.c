/**
  ******************************************************************************
  * @file           : picksort.c
  * @author         : Kenny
  * @brief          : None
  * @attention      : None
  * @date           : 2023/10/10
  ******************************************************************************
  */
#include <stdlib.h>
#include <string.h>
#include "picksort.h"
void picksort(void *array,int numElements,size_t elementSize,int(*cmp)(const void*,const void*))
{
    char * elements = (char *)array;
    unsigned char flag = 0;
    for(int i = 0;i<numElements-1;++i)
    {
        void *currentElement = elements + i * elementSize;
        void *min = currentElement;
        for(int j = i+1;j<numElements;++j)
        {
            void *searchElement = elements + j * elementSize;
            if(cmp(min,searchElement)>0)
            {
                flag = 1;
                min = searchElement;
            }
        }
        if(flag)
        {
            char *temp = (char *) malloc(elementSize);
            memcpy(temp,min,elementSize);
            memcpy(min,currentElement,elementSize);
            memcpy(currentElement,temp,elementSize);
            free(temp);temp=NULL;
        }
    }
}