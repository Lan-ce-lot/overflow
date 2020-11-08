/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
int t, n;


// 
// 
const int KEY_LEN = 5;
const int SYMBOLS_LEN = 10;
string key[KEY_LEN] = {"if","then","else","while","do"};
char symbols[SYMBOLS_LEN] = {'+', '-', '*', '/', '>', '<', '=', '(', ')', ';'};

bool IsSymbols(char c) {
	for (int i = 0; i < SYMBOLS_LEN; i++) {
		if (symbols[i] == c) {
			return true;
		}
	}
	return false;
}

bool IsKey(string c) {
	for (int i = 0; i < KEY_LEN; i++) {
		if (key[i] == c) {
			return true;
		}
	}
	return false;
}

bool IsLetter(char c) {
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

bool IsA_F(char c) {
	return c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F';
}

bool IsDigit(char c) {
	return c >= '0' && c <= '9';
}

void dfs1(FILE * fpin, string str) {
	char ch;
	if ((ch = fgetc(fpin)) != EOF && (IsLetter(ch) || ch == '_' || IsDigit(ch))) {
		dfs1(fpin, str + ch);
	} else {
		fseek(fpin, -1L, SEEK_CUR);
		if (IsKey(str)) cout << '<' << str << " , " << "->" << endl;
		else cout << '<' << "0" << " , " << str << '>' << endl;	
	}
}

void scan(FILE * fpin) {
	char ch;
	while ((ch=fgetc(fpin))!=EOF) {
		string tem="";
		if (ch != ' ' && ch != '\t' && ch != '\n') {
			
			if (IsLetter(ch) || ch == '_') { 
				tem += ch;
				dfs1(fpin, tem);
//				tem += ch;
//				while ((ch=fgetc(fpin))!=EOF && (IsLetter(ch) || ch == '_' || IsDigit(ch))) {
//					tem += ch;
//				}
//				fseek(fpin, -1L, SEEK_CUR);
//				if (IsKey(tem)) cout << '<' << tem << " , " << "->" << endl;
//				else cout << '<' << "0" << " , " << tem << '>' << endl;
			} else if (IsDigit(ch)) { 
				if (ch == '0') {
					ch = fgetc(fpin);
					if (ch >= '0' && ch <= '7') {
						while(ch >= '0' && ch <= '7') {
							tem += ch;
						    ch=fgetc(fpin);
						}
						fseek(fpin, -1L, 1);
						cout<<"<2 , " << tem << ">" <<endl;
					} else if (ch == 'x'){
						ch=fgetc(fpin);
						while(IsDigit(ch) || IsA_F(ch)) {
							tem += ch;
						    ch=fgetc(fpin);
						}
						fseek(fpin, -1L, 1);
						cout<<"<3 , " << tem << ">" <<endl;
					}
				} else {
					while (IsDigit(ch)) {
						tem += ch;
						ch = fgetc(fpin);
					}
					fseek(fpin, -1L, 1);
					cout<<"<1 , " << tem << ">" <<endl;
				}
			} else if (IsSymbols(ch)) {
				cout << '<' << ch << " , ->" << endl;
			} else {
				cout << "glznb!!!" << endl;
			}
		}
	}
}

int main()
{
   	FILE * fpin;
   	cout<<"词法分析器输出："<<endl;
   	for(;;){
       	if((fpin=fopen("D:\\work\\C++\\old\\master\\编译原理\\test.txt","r"))!=NULL) break;
       	else {
       	cout<<"文件路径错误\n";return 0;
	   	}
    }
   	scan(fpin);
//   system("pause");
   	fclose(fpin);
    return 0;
}

