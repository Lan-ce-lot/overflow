#include<bits/stdc++.h>
using namespace std;
vector<double> ans;
int a, b, c;
void ShengJin(double a,double b,double c,double d)
{
	double A=b*b-3*a*c;
	double B=b*c-9*a*d;
	double C=c*c-3*b*d;
	double f=B*B-4*A*C;
	double i_value;
	double Y1,Y2;
	if (fabs(A)<1e-6 && fabs(B)<1e-6)//公式1
	{
		ans.push_back(-b/(3*a));
		ans.push_back(-b/(3*a));
		ans.push_back(-b/(3*a));
	}
	else if (fabs(f)<1e-6)   //公式3
	{
		double K=B/A;
		ans.push_back(-b/a+K);
		ans.push_back(-K/2);
		ans.push_back(-K/2);
	}
	else if (f>1e-6)      //公式2
	{
		Y1=A*b+3*a*(-B+sqrt(f))/2;
		Y2=A*b+3*a*(-B-sqrt(f))/2;
		double Y1_value=(Y1/fabs(Y1))*pow((double)fabs(Y1),1.0/3);
		double Y2_value=(Y2/fabs(Y2))*pow((double)fabs(Y2),1.0/3);
		ans.push_back((-b-Y1_value-Y2_value)/(3*a));//虚根我不要
		//虚根还是看看吧，如果虚根的i小于0.1，则判定为方程的一根吧。。。
		i_value=sqrt(3.0)/2*(Y1_value-Y2_value)/(3*a);
		if (fabs(i_value)<1e-1)
		{
			ans.push_back((-b+0.5*(Y1_value+Y2_value))/(3*a));
		}
	}
	else if (f<-1e-6)   //公式4
	{
		double T=(2*A*b-3*a*B)/(2*A*sqrt(A));
		double S=acos(T);
		ans.push_back((-b-2*sqrt(A)*cos(S/3))/(3*a));
		ans.push_back((-b+sqrt(A)*(cos(S/3)+sqrt(3.0)*sin(S/3)))/(3*a));
		ans.push_back((-b+sqrt(A)*(cos(S/3)-sqrt(3.0)*sin(S/3)))/(3*a));
	}
}
int main(){
	int x, y;
	while(cin >> a >> b >> c){
		ans.clear();
		ShengJin(1, -a, -b, -c);
		sort(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i++){
			if(ans[i] > 0){
				printf("%d", (int)(ans[i]+0.5));
			}
			else printf("%d", (int)(ans[i]-0.5));
			if(i != ans.size() - 1)printf(" ");
		}
		printf("\n");
	}
	return 0;
}

