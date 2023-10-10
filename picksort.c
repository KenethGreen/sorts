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
    char * elements = (char *)array;                                // 1 byte each offset
    unsigned char flag = 0;
    for(int i = 0;i<numElements-1;++i)
    {
        void *currentElement = elements + i * elementSize;          // pointer offset i step
        void *min = currentElement;                                 // initial min element pointer
        for(int j = i+1;j<numElements;++j)
        {
            void *searchElement = elements + j * elementSize;       // pointer offset i step
            if(cmp(min,searchElement)>0)                            // here is a new min element
            {
                flag = 1;                                           // find new min element behind the currentElement
                min = searchElement;                                // min points at the current min one
            }
        }
        if(flag)                                                    // if here found element that less than currentElement, swap them
        {
            char *temp = (char *) malloc(elementSize);
            memcpy(temp,min,elementSize);
            memcpy(min,currentElement,elementSize);
            memcpy(currentElement,temp,elementSize);
            free(temp);temp=NULL;
        }
    }
}