#include <stdio.h>
#include <omp.h>
//reduction
int main()
{
    double start = omp_get_wtime( );  //得到开始时间
    int i, n;
    float a[100], b[100], result;
    // initializations
    n = 100;
    result = 0.0;
    for (i = 0; i < n; i++)
    {
        a[i] = i * 1.0;   //向量a为1，2，3，...100
        b[i] = i * 2.0;   //向量b为2,4,6...200
        
    }
    #pragma omp parallel for private(i) reduction(+:result)
    for (i = 0; i < n; i++)
    {
        
        result = result + (a[i] * b[i]);    //计算向量的乘积
    }
    printf("a*b= %12.6lf\n", result);     //输出向量乘积
    double end = omp_get_wtime( );        //得到结束时间
    double wtick = omp_get_wtick( );      //Returns the number of seconds between processor clock ticks两秒之间的时间
  
    printf("start = %.16g\nend = %.16g\ndiff = %.16g seconds\n",  
             start, end, end - start);  
  
    printf("wtick = %.16g\n1/wtick = %.16g\n",  
             wtick, 1.0 / wtick);      
    return 0;

}
