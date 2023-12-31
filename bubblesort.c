/**
  ******************************************************************************
  * @file           : bubblesort.c
  * @author         : Kenny
  * @brief          : None
  * @attention      : None
  * @date           : 2023/10/9
  ******************************************************************************
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubblesort.h"

void bubblesort(void *array, int numElements, size_t elementSize, int (*cmp)(const void *, const void *)) {
    char * elements                 = (char *)array;                                // 1 byte per step

    for(int i = 1;i<numElements;++i)
    {
        for(int j = 0;j<numElements-i;++j)
        {
            void *currentElement    = elements + j * elementSize;                   // offset = j, pointer go-next j offset position
            void *nextElement       = elements + (j + 1) * elementSize;             // offset = j+1, pointer go-next j+1 offset position

            if(cmp(currentElement,nextElement)>0)                                   // if current element is larger than the next one, swap them
            {
                char *temp          = (char *)malloc(elementSize);                  // open up elementSize space which makes temp can store one element latter
                memcpy(temp,currentElement,elementSize);                            // store current element into temp
                memcpy(currentElement,nextElement,elementSize);                     // let current element equal to the next one
                memcpy(nextElement,temp,elementSize);                               // let the next element equal to the last one
                free(temp);                                                         // free space
                temp=NULL;
            }
        }
    }
}

