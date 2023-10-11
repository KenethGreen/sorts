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
    char *elements = (char *)array;                                     // 1 byte each step
    void *pivot = elements + high * size;                               // set pivot value to compare with
    int i = low -1;                                                     // initial start-index
    int j = high+1;                                                     // initial end-index
    void *currentElement = NULL;                                        // initial currentElement
    while(1)
    {
        ++i;                                                            // update low-edge
        --j;                                                            // update high-edge
        currentElement = elements + i * size;                           // set currentElement with offset i
        while((i<j)&&cmp(currentElement,pivot)<0)                       // if index i is legal and current-element is less than  pivot
        {
            ++i;                                                        // offset i go-next 1 step;
            currentElement = elements + i * size;                       // update currentElement
        }
        swap(&currentElement,&pivot,size);                              // swap elements stored in offset i and j space in array
        if(i==--j)                                                      // if j is not legal, jump out the while-loop
            break;
        currentElement = elements + j * size;                           // update currentElement
        while((i<j)&&cmp(currentElement,pivot)>0)                       // if index j is legal and current-element is larger than pivot
        {
            --j;                                                        // offset j go-front 1 step;
            currentElement = elements + j * size;                       // update currentElement
        }
        swap(&currentElement,&pivot,size);                              // swap elements stored in offset i and j space in array
        if(i+1>=j)                                                      // if index i+1 is not legal, jump out the while-loop
            break;
    }
    return i+1;                                                         // return the offset which the pivot pointed at now
}

void quicksort(void *array,int numElements,size_t elementSize,int low,int high,int(*cmp)(const void*,const void*))
{
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