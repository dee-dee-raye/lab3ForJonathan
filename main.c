//
//  main.c
//  lab3
//
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "omp.h"


void Count_sort(int a[], int n);
int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {5,89,123,78,45,7};
    
    Count_sort(arr, 6);
    //qsort(arr, 31110,sizeof(int), cmpfunc);
    for(int x =0; x < 6; x++)
    {
        printf("%d\n",arr[x]);
    }
    
    return 0;
}


void Count_sort(int a[], int n)
{
    int i, j, count;
    int* temp = malloc(n*sizeof(int));
    
   #pragma omp parallel for shared(a,temp,n) private(i, j, count)
    for(i=0; i <n; i++)
    {
        count =0;

        for(j=0; j<n; j++)
        {
            if(a[j] < a[i])
                count ++;
            else if(a[j] == a[i] && j < i)
                count ++;
        }
        temp[count] = a[i];
    }
    memcpy(a, temp, n*sizeof(int));
    free(temp);
    
    
   
}
