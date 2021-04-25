#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double a = 1, b, c, d, A, B, C, D; 
vector<double> s;
int main()
{
	while (cin >> b >> c >> d) {
		s.clear();
		s.resize(3);
		b = - b, c = - c, d = -d;
		double A=b*b-3*a*c;
		double B=b*c-9*a*d;
		double C=c*c-3*b*d;
		D = B * B - 4 * A * C;
		if (fabs(A) < 1e-6 && fabs(B) < 1e-6) {
			s[1] = s[0] = s[2] = -b/(3*a);
		} else if (fabs(D) < 1e-6) {
			double K=B/A;
			s[0] = s[1] = -K/2, s[2] = (-b/a+K);
		} else if (D < -1e-6) {
			double T=(2*A*b-3*a*B)/(2*A*sqrt(A));
			double O=acos(T);
			s[0] = ((-b-2*sqrt(A)*cos(O/3))/(3*a));
			s[1] = ((-b+sqrt(A)*(cos(O/3)+sqrt(3.0)*sin(O/3)))/(3*a));
			s[2] = ((-b+sqrt(A)*(cos(O/3)-sqrt(3.0)*sin(O/3)))/(3*a));
		} else if (D > 1e-6){
			s.clear();
			double Y1=A*b+3*a*(-B+sqrt(D))/2;
			double Y2=A*b+3*a*(-B-sqrt(D))/2;
			double Y1_value=(Y1/fabs(Y1))*pow((double)fabs(Y1),1.0/3);
			double Y2_value=(Y2/fabs(Y2))*pow((double)fabs(Y2),1.0/3);
			s.push_back((-b-Y1_value-Y2_value)/(3*a));
			double i_value=sqrt(3.0)/2*(Y1_value-Y2_value)/(3*a);
			if (fabs(i_value)<1e-1)
			{
				s.push_back((-b+0.5*(Y1_value+Y2_value))/(3*a));
			}
		}
		
		sort(s.begin(), s.end());
		for(int i = 0; i < 3; i++){
			if(s[i] > 0){
				printf("%d", (int)(s[i]+0.5));
			}
			else printf("%d", (int)(s[i]-0.5));
			if(i != 2)printf(" ");
		}
		printf("\n");
	}
}

