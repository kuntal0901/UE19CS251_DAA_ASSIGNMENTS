#include <stdio.h>
#include "SelectionSort.h"
void Swap(int* x,int* y)
{
     int t;
     t=*x;
     *x=*y;
     *y=t;
}
long long int SelectionSort(int* A,int n)
{  
    long long int count=0;
    int minposition;
    for(int i=0;i<=(n-2);i++)
      {
          minposition=i;
          for(int j=i+1;j<=(n-1);j++)
           {
                count++;
               if(A[j]<A[minposition])
               {
                   minposition=j;
                  
               }
            }
          Swap(&A[i],&A[minposition]);
       }
      return count;
}

