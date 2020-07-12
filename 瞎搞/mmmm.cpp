#include <stdio.h>

int average(int score[]);
int main()
{
	int score[10]={1,10,20,30,40,50,60,70,80,90};
	int result = 0;

     result=average(score);
	 printf("%d\n",result);
 }
 int average(int score[])
 {
 	int i,result = 0;
 	for(i=0;i<=9;i++)
 	{
 		result+=score[i];
// 		printf("%d\n", result);
	 }
//    printf("%d\n", result);
	result/=10;
    return result;
 }
