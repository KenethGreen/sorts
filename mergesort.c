/**
  ******************************************************************************
  * @file           : mergesort.c
  * @author         : Kenny
  * @brief          : realized mergesort function
  * @attention      : None
  * @date           : 2023/10/11
  ******************************************************************************
  */

#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

void merge(void *array,int start,int mid,int end,size_t elementSize,int(*cmp)(const void*,const void*))
{
    char *elements = (char *)array;                                                     // 1 byte each step
    if(start>=end)                                                                      // equal to or less than 1 element, don`t need to merge
        return;
    if(end-start==1)                                                                    // here`re only two elements, sort directly
    {
        if(cmp(elements+start * elementSize,elements + end * elementSize)>0)
        {
            void *tmp = (void *)malloc(elementSize);                                    // open up space to store one element temporary
            memcpy(tmp,elements+start * elementSize,elementSize);                       // copy element from address (elements+start*elementSize) to tmp
            memcpy(elements+start*elementSize,elements+end * elementSize,elementSize);  // copy element from address (elements+end*elementSize) to address (elements+start * elementSize)
            memcpy(elements+end*elementSize,tmp,elementSize);                           // copy element from tmp to address (elements+end*elementSize)
            free(tmp);tmp=NULL;
        }                                                                               // free space
        return;
    }
    void *tmp = (void *) malloc((end-start+1) * elementSize);                           // open up space to store elements temporary
    int index = 0;                                                                      // index of tmp
    int i = start;                                                                      // index of the front part
    int j = mid+1;                                                                      // index of the next part
    void *front = NULL;                                                                 // initial a pointer pointing at the element in the front part
    void *next = NULL;                                                                  // initial a pointer pointing at the element in the next part
    // compare elements between the front part and the next part
    while(i<=mid)
    {
        front = elements + i * elementSize;                                             // catch the index i element in the front part
        while(j<=end)
        {
            next = elements + j * elementSize;                                          // catch the index j element in the next part
            if(cmp(front,next)>=0)                                                      // if the front element is equal to or larger than the next one
            {
                memcpy(tmp+index * elementSize,next,elementSize);                       // store the less one
                ++index;                                                                // index offset
                ++j;                                                                    // index offset
            }
            else{
                memcpy(tmp+index * elementSize,front,elementSize);                      // store the less one
                ++index;
                ++i;
                break;                                                                  // go and get the next-front element in the front part
            }
        }
        if(j>end)                                                                       // if the next part has been search over
            break;
    }
    while(i<=mid)                                                                       // if here`re still elements in the front part
    {
        front = elements + i * elementSize;
        memcpy(tmp+index *elementSize,front,elementSize);
        ++index;
        ++i;
    }
    while(j<=end)                                                                       // if here`re still elements in the next part
    {
        next = elements + j * elementSize;
        memcpy(tmp + index * elementSize,next,elementSize);
        ++index;
        ++j;
    }
    memcpy(elements+start * elementSize,tmp,(end-start+1)*elementSize);                 // copy elements sorted from array tmp to array elements
    free(tmp);tmp=NULL;                                                                 // free space
}

void mergesort(void *array,int numElement,size_t elementSize,int(*cmp)(const void*, const void*))
{
    int currSize = 2;                                                                   // initial currSize, which means the block size which split into. Here maybe lots of blocks in array split in this size scale
    int i = 0;                                                                          // initial index in array
    for(;currSize<numElement;currSize*=2,i=0)                                           // sorting in each block which size is from small to large but not larger than numElement
    {
        for(;i<numElement-1;i+=currSize)                                                // make sure index legal, offset currSize each loop
        {
            if(numElement-i<currSize)                                                   // means here`s the last block which may not contains currSize space
            {
                int mid = i+currSize/2-1;                                               // mid is still that way, but not i+(numElement-i)/2. we must make sure elements in block(i,mid) and block(mid+1,numElement-1) have been sort,that why mid still keep that way
                merge(array,i,mid,numElement-1,elementSize,cmp);                        // merge these two blocks, block(i,mid),block(mid+1,numElement-1)
                break;                                                                  // this size scale blocks have already sorted completely, break this loop and make currSize 2-time scale
            }
            int mid = i+currSize/2-1;                                                   //index to split a block
            merge(array,i,mid,i+currSize-1,elementSize,cmp);                            // merge these 2 new blocks into a new sort block
        }
    }
    int mid = currSize/2-1;                                                             // when jump out the loop, currSize must be larger than numElement. Maybe there still elements less.
    if(mid<=numElement-1)                                                               // there still elements less
        merge(array,0,mid,numElement-1,elementSize,cmp);                                // if these 2 most large blocks were merged, the whole array was sort
}