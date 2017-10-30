#include<stdio.h>
int fun(int n){//判断n是否是素数
    int i;
    for(i=2;i<n;i++)
        if(n%i==0) return 0;
    return 1; 
} 
int main()
{
     int m=0;
     int i;
     FILE *fp;//建立一个文件操作指针
     fp=fopen("out.txt","w+");//以追加的方式建立或打开out.txt，默认位置在你程序的目录下面
     for(i=2;i<=100000;i++)//循环判断
      {    
       if(fun(i))
        {
         fprintf(fp,"%d ",i);
         m++;
        }
      }
  fclose(fp); 
  printf("%s","2-100000的素数个数为:");
  printf("%d ",m);
  return 0;
}

