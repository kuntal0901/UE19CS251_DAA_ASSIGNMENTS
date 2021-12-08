#include <stdio.h>
#include "BubbleSort.h"
void Swap(int* x,int* y)
{
     int t;
     t=*x;
     *x=*y;
     *y=t;
}
int BubbleSort(int* A,int n)
{  
    long long int count=0;
    for(int i=0;i<=(n-2);i++)
      {
          for(int j=0;j<=(n-i-2);j++)
           {
                count++;
               if(A[j]>A[j+1])
               {
                   Swap(&A[j],&A[j+1]);
                  
               }
            }
         
       }
      return count;
}

