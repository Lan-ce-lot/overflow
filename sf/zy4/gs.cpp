#include<stdio.h>
#include<math.h>
int main() {
	float a,b,c,d,x1,x2,x3,p,q,i,w,s1,s2,s3,X2,X3;
	printf("请输入一元三次方程标准形式ax^3+bx^2+cx+d=0\n");
	printf("a b c d的值，用空格隔开\n");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	p=(3*a*c-b*b)/(3*a*a);
	q=(27*a*a*d-9*a*b*c+2*b*b*b)/(27*a*a*a);
	w=-0.5;
	s1=-b/(3*a);
	if(-q/2+sqrt(q*q/4+p*p*p/27)>0) {
		s2=pow((-q/2+sqrt(q*q/4+p*p*p/27)),1.0/3);
	} else {
		s2=-pow(-(-q/2+sqrt(q*q/4+p*p*p/27)),1.0/3);
	}
	if(-q/2-sqrt(q*q/4+p*p*p/27)>0) {
		s3=pow((-q/2-sqrt(q*q/4+p*p*p/27)),1.0/3);
	} else {
		s3=-pow(-(-q/2-sqrt(q*q/4+p*p*p/27)),1.0/3);
	}
	x1=s1+s2+s3;
	x2=s1+w*s2+w*s3;
	X2=sqrt(3)/2*s2+(-sqrt(3)/2)*s3;
	x3=s1+w*s2+w*s3;
	X3=sqrt(3)/2*s3+(-sqrt(3)/2)*s2;
	printf("第一个解为：%f\n",x1);
	if(X2>0) {
		printf("第二个解为：%f+%f*i\n",x2,X2);
	} else {
		printf("第二个解为：%f%f*i\n",x2,X2);
	}
	if(X3>0) {
		printf("第三个解为：%f+%f*i\n",x3,X3);
	} else {
		printf("第三个解为：%f%f*i\n",x3,X3);
	}
}