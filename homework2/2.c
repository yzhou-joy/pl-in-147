#include<stdio.h>
#include <omp.h>
int fun(int n){//判断n是否是素数
    int i;
    for(i=2;i<n;i++)
        if(n%i==0) return 0;
    return 1; 
} 
int main()
{
   int x,l,tid;
//串行
       double start = omp_get_wtime( );  //得到开始时间
       freopen("output.txt", "w", stdout); 
       int m=0;
        for(x=2;x<=100000;x++)      //循环判断
         {    
          if(fun(x))
           {
            printf("%d ",x);
	    tid = omp_get_num_threads();
            m++;
           }
         }
       fclose(stdout);
       double end = omp_get_wtime( );  //得到结束时间
       double time=end-start;
       tid = omp_get_num_threads();
       fprintf(stderr,"串行thread= %d 2-100000的素数个数=%d time=%.16g seconds 加速比=%d \n", tid, m, end-start,1);
//并行
     for (l=1;l<9;l++)
      {
       omp_set_num_threads(l);
       int m=0; 
       double start = omp_get_wtime( );  //得到开始时间
       freopen("output.txt", "w", stdout); 
       #pragma omp parallel for reduction(+:m)
        for(x=2;x<=100000;x++)      //循环判断
         {  
          tid = omp_get_num_threads();  
          if(fun(x))
           {
            printf("%d ",x);
	    //tid = omp_get_num_threads();   //测试一下此时的线程数
            m++;
           }
	  //tid = omp_get_num_threads();    //测试一下此时的线程数
         }
       fclose(stdout);
       double end = omp_get_wtime( );  //得到结束时间
       double time1=time/(end-start);
       fprintf(stderr,"并行thread= %d 2-100000的素数个数=%d time=%.16g seconds 加速比=%.16g \n", tid, m, end-start,time1);
      }
}

