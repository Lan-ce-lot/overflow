/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << "*" << a << "*" << endl
//int count_Vn = 0, count_Vt = 0, count_P = 0;
const int N = 1e3;

struct grammar {
	string Vn;		//Vn  文法的非终结符号集合
	string Vt;		//Vt  文法的终结符号集合
	char S;			//S   开始符号
					//P   产生式
	map<char, vector<string> > P;
}; 
void print_G(grammar g);

bool exitV(string str, char c) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == c) {
			return 1;
		}
	}
	return 0;
}


bool is_Vt(char c) {
	string Vt = "!@#$%^&*()_+-={}[]<>?/";
	for (int i = 0; i < Vt.size(); i++) {
		if (Vt[i] == c) return 1;
	}
	if (c >= 'a' && c <= 'z') return 1;
	return 0;
}

char GetBC(FILE* fpi) {					//子函数，用于读取一个非空格字符
	char ch;
	do {
		ch = fgetc(fpi);
	} while (ch == ' ');
	return ch;
}

// ******************************************************************
// 读入一句 
// ****************************************************************** 
void scanG(FILE* fpi, grammar &g) {
	if (feof(fpi))		return;

	char ch;
	char start;// 记录产生式开头的非终结符 
	string tem;// 记录对应候选式 

	ch = GetBC(fpi);
	if (ch >= 'A' && ch <= 'Z') {
		start = ch; 
		if (!exitV(g.Vn, ch)) {
			g.Vn += ch;
//			count_Vn++;
			ch = GetBC(fpi);
			if (ch == '-' && GetBC(fpi) == '>') {
				while (true) {
					ch = GetBC(fpi);
					if (ch == ';' || ch == '\n') break;
					if (is_Vt(ch) && !exitV(g.Vt, ch)) { // 
						g.Vt += ch;
					}
					if (ch == '|') {
						g.P[start].push_back(tem);
						tem = "";
					} else tem += ch;
				}
			}
			g.P[start].push_back(tem);
		} else {
			ch = GetBC(fpi);
			if (ch == '-' && GetBC(fpi) == '>') {
				while (true) {
					ch = GetBC(fpi);
					if (ch == ';' || ch == '\n') break;
					if (ch >= 'a' && ch <= 'z' && !exitV(g.Vt, ch)) { // 
						g.Vt += ch;
					} 
					if (ch == '|') {
						g.P[start].push_back(tem);
						tem = "";
					} else tem += ch;	
				}
			}
			g.P[start].push_back(tem);
		}
	}
}

void print_G(grammar g) {
	cout << "文法 " << endl; 
    for (int i = 0; i < g.Vn.size(); i++) {
    	char c = g.Vn[i];cout << c << "->";
    	for (int j = 0; j < g.P[c].size(); j++) {
    		if (j != 0) {
    			cout << '|' ;
			}
    		cout << g.P[c][j] ;
		}
		puts("");
	}
	cout << "开始符 " << g.S << endl;
	cout << "非终结符 " << g.Vn << endl;
    cout << "终结符 " << g.Vt << endl;
}

// ******************************************************************
// 预测分析程序 
// ****************************************************************** 

bool forecast(grammar g, string s) {
	
	
	
	
}

int main()
{
	FILE * fpin;
   	while (1) {
       	if((fpin=fopen("D:\\work\\C++\\old\\master\\编译原理\\sy2.txt","r"))!=NULL) break;
       	else {
       		cout<<"文件路径错误\n";return 0;
	   	}
    }
    grammar g;
    
	char ch;
	do {
		ch = GetBC(fpin);
	} while (ch <= 'A' || ch >= 'Z');
	g.S = ch;
	fseek(fpin, -1L, 1);
	
    while (!feof(fpin)) {
    	scanG(fpin, g);
	}
    print_G(g);

    return 0;
}

