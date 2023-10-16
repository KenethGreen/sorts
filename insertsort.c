/**
  ******************************************************************************
  * @file           : insertsort.c
  * @author         : Kenny
  * @brief          : None
  * @attention      : None
  * @date           : 2023/10/10
  ******************************************************************************
  */

#include <stdlib.h>
#include <string.h>
#include "insertsort.h"
void insertsort(void* array,int numElements,size_t elementSize,int(*cmp)(const void*,const void*))
{
    char *elements = (char *)array;
    for(int i = 0;i<numElements-1;++i)
    {
        void *currentElement = elements + i * elementSize;                      // pointer offset i step
        void *searchElement = NULL;
        for(int j = i+1;j<numElements;++j)
        {
            searchElement = elements + j * elementSize;                         // pointer offset j step
            if(cmp(currentElement,searchElement)>0)                             // compare with this two elements
            {
                char *temp = (char *) malloc(elementSize);
                memcpy(temp,searchElement,elementSize);
                memcpy(searchElement,currentElement,elementSize);
                memcpy(currentElement,temp,elementSize);
                free(temp);temp = NULL;
                for(int k = i-1;k>=0;--k)                                       // compare with elements which before the currentElement
                {
                    char *before = elements + k * elementSize;                  // before element
                    if(cmp(before,currentElement)>0)
                    {
                        temp = (char *) malloc(elementSize);
                        memcpy(temp,currentElement,elementSize);
                        memcpy(currentElement,before,elementSize);
                        memcpy(before,temp,elementSize);
                        currentElement = before;                                  // update the currentElement
                        free(temp);temp=NULL;
                    }
                    else                                                        // if the currentElement is larger than the before one, means sort successfully from start to the currentElement
                        break;
                }
                break;                                                          // insert element one by one. if inserted, break and go into the next loop
            }
        }
    }
}