# include<iostream>
# include<cstring>
# include<algorithm>
# include<string>

#include<bits/stdc++.h>
using namespace std;
int  a, b, ans;
int main() {
	while (cin >> a >> b) {
		a += b;string s = to_string(a);
		int n = s.size();
		if (a < 0) {
			
			n--;
			s = s.substr(1, n);
//			cout << s <<endl;
			cout << '-';
			for (int i = 0; i < n; i++) {
				cout << s[i];
				if ((n - i - 1)% 3 == 0 && i != n - 1) {
					cout << ',';
				}
			}
			
			puts("");
		} else {
			for (int i = 0 ; i < n; i++) {
				cout <<s[i] ;
				if ((n - i - 1) % 3 == 0 && i != n - 1) {
					cout << ',';
				}
			}
			puts("");
		}
	}
	return 0;
} 

//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<cstring>
//using namespace std;
//int main(){
//    int a,b;
//    cin>>a>>b;
//    int c=a+b;
//    if(c<0) cout<<'-';
//    c=abs(c);
//    char s[20];
//    sprintf(s,"%d",c);
//    int len=strlen(s);
//    //if(len<=3) {cout<<s;return 0;}
//    int m=len/3,n=len%3,start=0;
//    //cout<<"m="<<m<<' '<<"n="<<n<<endl;
//    if(n==0) {cout<<s[0]<<s[1]<<s[2];start=3;m--;}
//    else if(n==1) {cout<<s[0];start=1;}
//    else if(n==2) {cout<<s[0]<<s[1];start=2;}
//    while(m!=0){
//        cout<<',';
//        cout<<s[start]<<s[start+1]<<s[start+2];
//        start+=3;
//        m--;
//    }
//    return 0;
//}
