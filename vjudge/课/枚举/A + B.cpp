#include <stdio.h>；
#include <math.h>；
#include <iostream>;
using namespace std;
int main(){
	float a,b=0;
	while(1){
            b = 0;
		scanf("%f",&a);
		if(a==0)
		  break;
		for(int i=2;;i++){
			b+=1.0/i;
			if(b>=a)
			{
				printf("%d card(s)\n",i);
				break;
			}
		}
	}
	return 0;
}
