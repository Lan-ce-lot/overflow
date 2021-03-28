#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std; 
void ShengJin(double a,double b,double c,double d,vector<double> &X123)
{
	/************************************************************************/
	/* ʢ��ʽ������η��̵Ľ� 
	   �¶���f=B^2-4AC
           ����ֻҪ��ʵ���������Ҫ�Լ����������ó���
	*/
	/************************************************************************/
	double A=b*b-3*a*c;
	double B=b*c-9*a*d;
	double C=c*c-3*b*d;
	double f=B*B-4*A*C;
	double i_value;
	double Y1,Y2;
	if (fabs(A)<1e-6 && fabs(B)<1e-6)//��ʽ1
	{
		X123.push_back(-b/(3*a));
		X123.push_back(-b/(3*a));
		X123.push_back(-b/(3*a));
	}
	else if (fabs(f)<1e-6)   //��ʽ3
	{
		double K=B/A;
		X123.push_back(-b/a+K);
		X123.push_back(-K/2);
		X123.push_back(-K/2);
	}
	else if (f>1e-6)      //��ʽ2
	{
		Y1=A*b+3*a*(-B+sqrt(f))/2;
		Y2=A*b+3*a*(-B-sqrt(f))/2;
		double Y1_value=(Y1/fabs(Y1))*pow((double)fabs(Y1),1.0/3);
		double Y2_value=(Y2/fabs(Y2))*pow((double)fabs(Y2),1.0/3);
		X123.push_back((-b-Y1_value-Y2_value)/(3*a));//����Ҳ�Ҫ
		//������ǿ����ɣ���������iС��0.1�����ж�Ϊ���̵�һ���ɡ�����
		i_value=sqrt(3.0)/2*(Y1_value-Y2_value)/(3*a);
//		if (fabs(i_value)<1e-1)
//		{
//			X123.push_back((-b+0.5*(Y1_value+Y2_value))/(3*a));
//		}
	}
	else if (f<-1e-6)   //��ʽ4
	{
		double T=(2*A*b-3*a*B)/(2*A*sqrt(A));
		double S=acos(T);
		X123.push_back((-b-2*sqrt(A)*cos(S/3))/(3*a));
		X123.push_back((-b+sqrt(A)*(cos(S/3)+sqrt(3.0)*sin(S/3)))/(3*a));
		X123.push_back((-b+sqrt(A)*(cos(S/3)-sqrt(3.0)*sin(S/3)))/(3*a));
	}
}
int main(){
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF){
		vector<double> vc;
		ShengJin(1,-a*1.0,-b*1.0,-c*1.0,vc);
//		cout<<vc.size()<<endl;
//		cout<<vc[0]<<endl;
		if(vc.size()<3){
			printf("%d %d %d\n",(int)vc[0],(int)vc[0],(int)vc[0]);
			continue;
		} 
		sort(vc.begin(),vc.begin()+3);
		printf("%lf %lf %lf\n",vc[0],vc[1],vc[2]);
//		printf("%d %d %d\n",(int)vc[0],(int)vc[1],(int)vc[2]);
	}
	return 0;
}
