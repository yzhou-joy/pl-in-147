#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>

int fun(int n){//�ж�n�Ƿ�������
    int i;
    for(i=2;i<n;i++)
        if(n%i==0) return 0;
    return 1; 
} 

int main()
{
   int x;
   double startwtime = 0.0, endwtime;

//����
       startwtime=clock();  //�õ���ʼʱ��
       freopen("output.txt", "w", stdout); 
       int m=0;
        for(x=2;x<=100000;x++)      //ѭ���ж�
         {    
          if(fun(x))
           {
            printf("%d ",x);;
            m++;
           }
         }
       fclose(stdout);
       endwtime=clock();//�õ�����ʱ��
       fprintf(stderr,"serial : the number of prime between 2-100000 is : %d   running time is %f \n", m, (endwtime-startwtime)/CLOCKS_PER_SEC);
  return 0;          
}