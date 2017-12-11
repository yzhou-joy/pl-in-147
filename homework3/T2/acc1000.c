#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include <accel.h>
#include <accelmath.h>

int main()
{
		struct timeval t1, t2, t3;
    long time1;
    
    int i, n;
    int a[1000], b[1000], result=0;
    // initializations
    n = 1000;
    for (i = 0; i < n; i++)
    {
        a[i] = i * 1;   //����aΪ1��2��3��...100
        b[i] = i * 2;   //����bΪ2,4,6...200
        
    }
    gettimeofday( &t1, NULL );  //�õ���ʼʱ��
    #pragma acc parallel 
    for (i = 0; i < n; i++)
    {
        
        result = result + (a[i] * b[i]);    //���������ĳ˻�
    }
    gettimeofday( &t2, NULL );//�õ�����ʱ��
    time1 = (t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec - t1.tv_usec);
    printf("%13ld is the result of a*b\n", result);     //��������˻�  
    printf( "%13d iterations completed\n", n );
    printf( "%13ld microseconds on parallel\n", time1 );                
    return 0;

}
