#include<iostream>
 
using namespace std;
typedef long long ll;
#define PI 3.1415927
int main()

{
	char a[50],b[10];
	int i,j;
	gets(a);
	gets(b);
	while(a[i]!=0) i++;
	j=0;
	while(b[j]!=0&&j<5)
	{
		a[i]=b[j];
		j++;
		i++;
	 } 
	 a[i]='\0';
	 puts(a);
	 
	


	return 0;

}
