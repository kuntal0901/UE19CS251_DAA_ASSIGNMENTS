#include <stdio.h>
#include "QuickSort.h"
#include <stdlib.h>
#include <stdio.h>

static int count=0;
void Swap(int* x,int* y)
{
     int t=*x;
     *x=*y;
     *y=t;
}
int partition(int* A,int start,int end)
{
   int pivotelement=A[start];
   int i=start,j=end+1;
   
   do
   {
        do
         {
           i++;
           count++;
             
         }while(A[i]<=pivotelement && i<end);
        do
         {
           j--;
           count++;
           
         }while(A[j]>pivotelement);
         if(i<j)
         {
            Swap(&A[i],&A[j]);
         }
    }while(i<=j);
    Swap(&A[start],&A[j]);
   return j;
 }
int QuickSort(int* A,int start,int end)
{  
    int splitposition;
    if(start<end)
    {
       splitposition=partition(A,start,end);
    
       QuickSort(A,start,splitposition-1);
         
       QuickSort(A,splitposition+1,end);
        
    }
     return count;
    
}
