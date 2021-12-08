#include <stdio.h>
#include "MergeSort.h"
#include <stdlib.h>
#include <stdio.h>
int Merge(int arr[], int start, int end, int mid)
{
    int i, j, k,count=0;
    int n1 = mid - start + 1;
    int n2 = end - mid;
 
 
    int B[n1], C[n2];
 
 
    for (i = 0; i < n1; i++)
        B[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        C[j] = arr[mid + 1 + j];
 
 
    i = 0; 
    j = 0; 
    k = start; 
    while (i < n1 && j < n2) {
        if (B[i] <= C[j]) {
            arr[k] = B[i];
            i++;
            count++;
        }
        else {
            arr[k] = C[j];
            j++;
            count++;
        }
        k++;
    }
 
    
    while (i < n1) {
        arr[k] = B[i];
        i++;
        k++;
    }
 
    
    while (j < n2) {
        arr[k] = C[j];
        j++;
        k++;
    }
return count;    
}


int MergeSort(int* A,int start,int end)
{  
    int mid;
    int count=0;
    if(start<end)
    {
       mid=(start+end)/2;
       MergeSort(A,start,mid);
       MergeSort(A,mid+1,end);
       count+=Merge(A,start,end,mid);
    }
    return count;
}
