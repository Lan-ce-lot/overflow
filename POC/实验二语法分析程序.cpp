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
	string Vn;		//Vn  �ķ��ķ��ս���ż���
	string Vt;		//Vt  �ķ����ս���ż���
	char S;			//S   ��ʼ����
					//P   ����ʽ
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

char GetBC(FILE* fpi) {					//�Ӻ��������ڶ�ȡһ���ǿո��ַ�
	char ch;
	do {
		ch = fgetc(fpi);
	} while (ch == ' ');
	return ch;
}

// ******************************************************************
// ����һ�� 
// ****************************************************************** 
void scanG(FILE* fpi, grammar &g) {
	if (feof(fpi))		return;

	char ch;
	char start;// ��¼����ʽ��ͷ�ķ��ս�� 
	string tem;// ��¼��Ӧ��ѡʽ 

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
	cout << "�ķ� " << endl; 
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
	cout << "��ʼ�� " << g.S << endl;
	cout << "���ս�� " << g.Vn << endl;
    cout << "�ս�� " << g.Vt << endl;
}

// ******************************************************************
// Ԥ��������� 
// ****************************************************************** 

bool forecast(grammar g, string s) {
	
	
	
	
}

int main()
{
	FILE * fpin;
   	while (1) {
       	if((fpin=fopen("D:\\work\\C++\\old\\master\\����ԭ��\\sy2.txt","r"))!=NULL) break;
       	else {
       		cout<<"�ļ�·������\n";return 0;
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

