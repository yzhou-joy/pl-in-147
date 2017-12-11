#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include <omp.h>

int main()
{
		struct timeval t1, t2;
    long time1;
   
    int i, n,result=0;
    int a[1000], b[1000];
    n = 1000;
    for (i = 0; i < n; i++)
    {
        a[i] = i * 1;   //向量a为1，2，3，...100
        b[i] = i * 2;   //向量b为2,4,6...200
        
    }
    gettimeofday( &t1, NULL );  //得到开始时间
    #pragma omp parallel for private(i) shared (a,b) reduction(+:result)
	    for (i = 0; i < n; i++)
	    {
	        
	        result = result + (a[i] * b[i]);    //计算向量的乘积
	    }
   
    gettimeofday( &t2, NULL );//得到结束时间
    time1 = (t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec - t1.tv_usec);
    printf("%13d is the result of a*b\n", result);     //输出向量乘积  
    printf( "%13d iterations completed\n", n );
    printf( "%13ld microseconds on parallel\n", time1 );                
    return 0;

}
