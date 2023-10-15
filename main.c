#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubblesort.h"
#include "insertsort.h"
#include "quicksort.h"
#include "picksort.h"
#include "mergesort.h"
#include "sorts.h"
int main() {
    srand(time(0));
    int n = 100;
    int a[100];
    int max = 100;
    int min = 0;
    for(int i = 0;i<n;++i)
    {
        a[i]=(rand() % (max - min + 1)) + min;
        printf("%d ",a[i]);
    }
    printf("\n");
    mergesort(&a,n,sizeof(int),cmpInt);
    for(int i = 0;i<n;++i)
    {
        if(!(i%10)&&i>0)
            printf("\n");
        printf("%d ",a[i]);
    }
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
