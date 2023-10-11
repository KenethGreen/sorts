/**
  ******************************************************************************
  * @file           : quicksort.c
  * @author         : Kenny
  * @brief          : realized swap, partition and quicksort functions
  * @attention      :
  *                 swap function:          realized to swap 2 elements in array
  *
  *                 partition function:     sort 1 element, make array into 2
  *                                         parts and return the
  *                                         part-index(mid-index)
  *
  *                 quicksort function:     quicksort for array
  * @date           : 2023/10/10
  ******************************************************************************
  */

#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
void swap(void **a,void **b,size_t size)
{
    char **x = (char **)a;                  // 1 byte each step
    char **y = (char **)b;                  // 1 byte each step
    char *temp = (char *) malloc(size);     // open up space for swap
    // memory copy
    memcpy(temp,*x,size);
    memcpy(*x,*y,size);
    memcpy(*y,temp,size);
    // swap positions which pointed at;
    char *tmp = *y;
    *y = *x;
    *x = temp;
    free(temp);temp = NULL;                  // free space
}

int partition(void *array,int numElements,size_t size,int low,int high,int(*cmp)(const void*,const void*))
{
    if(low == high)                                                     // if here is one element in this part
        return high;
    char *elements = (char *)array;                                     // 1 byte each step
    void *pivot = elements + high * size;                               // set pivot value to compare with
    int i = low - 1;                                                    // initial the select pointer
    void *currentElement = NULL;                                        // initial the currentElement for j
    void *searchElement = NULL;                                         // initial the searchElement for i
    for(int j = low;j<high;++j)                                         // compare elements whose offset is from 0 to high-1 with pivot whose offset is high
    {
        currentElement = elements + j * size;                           // update curentElement
        if(cmp(currentElement,pivot)<0)                                 // if true, the select pointer go-next 1 step
        {
            ++i;                                                        // the select pointer goes next
            if(i!=j)                                                    // if true, swap searchElement and currentElement
            {
                searchElement = elements + i * size;
                swap(&searchElement,&currentElement,size);
            }
        }
    }
    currentElement = elements + high * size;                            // select the high element also the last element
    searchElement = elements + (i+1) * size;                            // select the offset(i+1) element
    swap(&searchElement,&currentElement,size);                          // swap them
    return i+1;
}

void quicksort(void *array,int numElements,size_t elementSize,int low,int high,int(*cmp)(const void*,const void*))
{
    if(low == high)
        return;
    int stack[high-low+1];                                                              // initial a stack for storing index
    int top = -1;                                                                       // initial top index
    stack[++top] = low;                                                                 // initial low-edge
    stack[++top] = high;                                                                // initial high-edge

    while(top>=0)
    {
        high = stack[top--];                                                            // get high-edge
        low = stack[top--];                                                             // get low-edge

        int pivotIndex = partition(array,numElements,elementSize,low,high,cmp);         // sort 1 element and get mid-edge which be used to divide part[low,high] into 2 part

        if(pivotIndex-1>low){                                                           // if true, store the low-edge and high-edge for left-part
            stack[++top] = low;                                                         // low-edge
            stack[++top] = pivotIndex - 1;                                              // high-edge
        }

        if(pivotIndex + 1 < high)                                                       // if true, store the low-edge and high-edge for right-part
        {
            stack[++top] = pivotIndex + 1;                                              // low-edge
            stack[++top] = high;                                                        // high-edge
        }
    }
}