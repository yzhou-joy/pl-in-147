#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include <accel.h>
#include <accelmath.h>

int fun(int n){//�ж�n�Ƿ�������
    int i;
    for(i=2;i<n;i++)
        if(n%i==0) return 0;
    return 1; 
} 

int main()
{
	struct timeval t1, t2;
   int x;
   long time1;
	 gettimeofday( &t1, NULL );  //�õ���ʼʱ��
       freopen("output.txt", "w", stdout); 
       int m=0;
       #pragma acc loop 
       for(x=2;x<=100000;x++)      //ѭ���ж�
         {    
          if(fun(x))
           {
            printf("%d ",x);
            m++;
           }
         }
       fclose(stdout);
       gettimeofday( &t2, NULL );//�õ�����ʱ��
       time1 = (t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec - t1.tv_usec);
       fprintf(stderr,"OpenACC : the number of prime between 2-100000 is : %d   running time is %ld microseconds \n", m, time1);
  return 0;
}