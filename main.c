#include <stdio.h>
#include "bubblesort.h"
#include "insertsort.h"
#include "quicksort.h"
#include "picksort.h"
#include "sorts.h"
int main() {
//    int a[4]={4,3,2,1};                               // int
    float a[4] = {3.2f,3.1f,4.5f,2.3f};                 // float
//    const char *a[] = {"hello","world","help","I"};   // string
    int n = sizeof(a)/sizeof(a[0]);
//    bubblesort(a,n,sizeof(int),cmpInt);
//    insertsort(a,n,sizeof(float),cmpFloat);
    quicksort(a,n,sizeof(float),0,n-1,cmpFloat);
//    bubblesort(a,n,sizeof(char*),cmpString);
    for(int i = 0;i<n;++i)
//        printf("%d ",a[i]);
        printf("%.1f ",a[i]);
//        printf("%s ",a[i]);
    return 0;
}
