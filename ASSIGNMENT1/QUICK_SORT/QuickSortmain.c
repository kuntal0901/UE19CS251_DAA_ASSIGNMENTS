#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"
#include <time.h>
void main()
{
   FILE *fp1;
   FILE *fp2;
   fp1=fopen("QuickSorttime.txt","w");
   fp2=fopen("QuickSortcomparision.txt","w");
   int* A,comp;
  for(int i=100;i<=2000;i+=100)
    {
      A=malloc(i*sizeof(int));
      for(int j=0;j<i;j++)
      {
         A[j]=rand();
      }
      clock_t start,end;
      start=clock();   
      comp=QuickSort(A,0,i-1);
      end=clock();
      double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
      fprintf(fp1,"%d\t%lf\n",i,time_taken);
      fprintf(fp2,"%d\t%d\n",i,comp);
      free(A);
      
}   
  fclose(fp1);       
  fclose(fp2);
}
