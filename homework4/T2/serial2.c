#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>

int fun(int n){//判断n是否是素数
    int i;
    for(i=2;i<n;i++)
        if(n%i==0) return 0;
    return 1; 
} 

int main()
{
   int x;
   double startwtime = 0.0, endwtime;

//串行
       startwtime=clock();  //得到开始时间
       freopen("output.txt", "w", stdout); 
       int m=0;
        for(x=2;x<=100000;x++)      //循环判断
         {    
          if(fun(x))
           {
            printf("%d ",x);;
            m++;
           }
         }
       fclose(stdout);
       endwtime=clock();//得到结束时间
       fprintf(stderr,"serial : the number of prime between 2-100000 is : %d   running time is %f \n", m, (endwtime-startwtime)/CLOCKS_PER_SEC);
  return 0;          
}