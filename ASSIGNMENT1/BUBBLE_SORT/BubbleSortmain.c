#include <stdio.h>
#include <stdlib.h>
#include "BubbleSort.h"
#include <time.h>
void main()
{
   FILE *fp1;
   FILE *fp2;
   fp1=fopen("BubbleSorttime.txt","w");
   fp2=fopen("BubbleSortcomparision.txt","w");
   int* A,comp;
   
   for(int i=100000;i<=1000000;i+=50000)
    {
      A=malloc(i*sizeof(int));
      for(int j=0;j<i;j++)
      {
         A[j]=rand();
      }
      clock_t t;
      t=clock();   
      comp=BubbleSort(A,i);
      t=clock()-t;
      double time_taken=((double)t)/CLOCKS_PER_SEC;
      fprintf(fp1,"%d\t%lf\n",i,time_taken);
      fprintf(fp2,"%d\t%d\n",i,comp);
}   
  fclose(fp1);       
  fclose(fp2);
}
