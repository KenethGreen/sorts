#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubblesort.h"
#include "insertsort.h"
#include "quicksort.h"
#include "picksort.h"
#include "mergesort.h"
#include "sorts.h"
/* choice one and make it 1 to start that sort */
#define BUBBLE  0                                           // bubble-sort
#define INSERT  0                                           // insert-sort
#define QUICK   0                                           // quick-sort
#define PICK    0                                           // pick-sort
#define MERGE   1                                           // merge-sort
int main() {
    srand(time(0));                                         // generate seed
    int n = 100;                                            // set the length of array a is n
    int a[100];                                             // declare array a
    int max = 100;                                          // max value in array
    int min = 0;                                            // min value in array
    for(int i = 0;i<n;++i)                                  // generate number for array a
    {
        a[i]=(rand() % (max - min + 1)) + min;
        printf("%d ",a[i]);
    }
    printf("\n");
    /* start to sort */
#if MERGE
    mergesort(&a,n,sizeof(int),cmpInt);
#elif BUBBLE
    bubblesort(&a,n,sizeof(int),cmpInt);
#elif INSERT
    insertsort(&a,n,sizeof(int),cmpInt);
#elif QUICK
    quicksort(&a,n,sizeof(int),0,n-1,cmpInt);
#elif PICK
    picksort(&a,n,sizeof(int),cmpInt);
#endif
    /* print ordered array */
    for(int i = 0;i<n;++i)
    {
        if(!(i%10)&&i>0)
            printf("\n");
        printf("%d ",a[i]);
    }
    /* Judge whether ordered or not */
    for(int i = 0;i<n-1;++i)
    {
        if(a[i]>a[i+1])
        {
            printf("\nfalse\n");
            return 0;
        }
    }
    printf("\ntrue\n");
    return 0;
}
