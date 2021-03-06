/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include<iostream>
#include<string>
#include<cstring>
#include<vector> 
#include<map>
#include<set>
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
// ������ݹ� 
// ****************************************************************** 
char get_Vn(string str) {// ����������ݹ� 
	for (int i = 0; i < 26; i++) {
		char c = (i + 'A');
		if (!exitV(str, c)) return c;
	}
	return ' ';
}

bool check_Vn_repeat(string s, vector<string> str) { // ������ʽ�Ұ벿�Ƿ���� 
	for (auto it : str) {
		if (s == it) {
			return true;
		}
	}
	return false;
}
// ******************************************************************
// ����ģ�� 
// ****************************************************************** 
map<char, bool> vis;
void dfs(grammar g, char c, string &res) {
	for (int i = 0; i < g.P[c].size(); i++) {
		for (int j = 0; j < g.P[c][i].size(); j++) {
			char tem_c = g.P[c][i][j];
			if (tem_c >= 'A' && tem_c <= 'Z' && vis[tem_c] == 0) {
				vis[tem_c] = 1;
				res += tem_c;
				dfs(g, tem_c, res);
			}
		}
	}
}

void simplify(grammar &g) {
	string tem = ""; // ��¼��ʼ���ɴ���ս�� 
	vis.clear();
	tem += g.S;
	vis[g.S] = 1;
	for (int i = 0; i < g.P[g.S].size(); i++) {
		
		for (int j = 0; j < g.P[g.S][i].size(); j++) {
			char c = g.P[g.S][i][j];
			if (vis[c] == 0 && c >= 'A' && c <= 'Z') {
				tem += c;
				vis[c] = 1;
			}
		}
	}
	string st = tem;
	for (int i = 0; i < tem.size(); i++) {
		dfs(g, tem[i], st);
	}
	
//	debug(st);
//	g.Vn = st;
	for (int i = 0; i < g.Vn.size(); i++) {
		if (!exitV(st, g.Vn[i])) {
			g.P[g.Vn[i]].clear();
		} 
	}
	g.Vn = st;
	puts("\n����");
	print_G(g);
}


void remove_left_recursion(grammar &g) {
//	bool flag[N];
//	memset(flag, 0, sizeof flag);
	// �滻
	grammar new_g;
	new_g.S = g.S, new_g.Vn = g.Vn, new_g.Vt = g.Vt;
	
	for (int i = g.Vn.size() - 1; i >= 0; i--) {
		char c = g.Vn[i]; // pi
		for (int j = g.Vn.size() - 1; j > i; j--) {
			
			char tem = g.Vn[j]; // pj target
			for (int k = 0; k < g.P[c].size(); k++) {
				if (g.P[c][k].find(tem, 0) == 0) {
					for (int z = 0; z < g.P[tem].size(); z++) {
						new_g.P[c].push_back(g.P[tem][z] + g.P[c][k].substr(1, g.P[c][k].size() - 1));
//						debug(g.P[tem][z] + g.P[c][k].substr(1, g.P[c][k].size() - 1));
//						debug(new_g.P[c][z]);
//						cout << c << ' ' << tem << endl; 
					}
				} 
				else if (!check_Vn_repeat(g.P[c][k], new_g.P[c])) {
//					cout << c << ' ' << tem << endl; 
//					debug(11);debug(g.P[c][k]);

					new_g.P[c].push_back(g.P[c][k]);
				}
				
			}
			g.P[c] = new_g.P[c];
			new_g.P[c].clear();
		}
		// 
		// ����ֱ����ݹ� 
		// ����ֻ����S��ͷ�Ĳ���ʽ����� 
		int tem_len =  g.Vn.size();
		for (int z = 0; z < tem_len; z++) {
			char c = g.Vn[z];
			for (int j = 0; j < g.P[c].size(); j++) {
				if (g.P[c][j][0] == c) {
					char new_c = get_Vn(g.Vn);
					g.Vn += new_c;
	//				g.P[g.S][j] = g.P[g.S][j].substr(1, g.P[g.S][j].size() - 1) + new_c;
					for (int k = 0; k < g.P[g.Vn[z]].size(); k++) {
						if (k != j) {
							g.P[g.S][k] += new_c;
						}
					} 
					
					g.P[new_c].push_back(g.P[c][j].substr(1, g.P[c][j].size() - 1) + new_c);
					g.P[new_c].push_back("@");
					if (!exitV(g.Vt, '@')) {
						g.Vt += "@";
					}
					g.P[c].erase(g.P[c].begin() + j);
				}
			}
		}

	}	
	print_G(g);
	// ���� 
	simplify(g);
} 

// ******************************************************************
// �������� 
// ��ȡ������
// ******************************************************************

void remove_left_gene(grammar &g) {
	map<char, vector<int> > m;
	for (int i = 0; i < g.Vn.size(); i++) {
		char c = g.Vn[i];
		m.clear();
		for (int j = 0; j < g.P[c].size(); j++) {
			m[g.P[c][j][0]].push_back(j);
		}
		
		for (auto it : m) {
			if (it.second.size() >= 2) {
				char new_Vn = get_Vn(g.Vn);
				g.Vn += new_Vn;
//				debug(new_Vn);
				for (auto it1 : it.second) {
					string str = g.P[c][it1].substr(1, g.P[c][it1].size() - 1);
					g.P[new_Vn].push_back(str);
					
				}
				for (auto it1 : it.second) {
					g.P[c].erase(g.P[c].begin() + it1);
				}
				string s(1,new_Vn);
				g.P[c].push_back(it.first + s);
			}
		}
	}
	print_G(g);
	simplify(g);
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
// ��FIRST�� 
// ****************************************************************** 
map<char, set<char> > FIRST;
void getFIRST(grammar g) {
	// 1 ���������һ���ս��
	for (int i = 0; i < g.Vt.size(); i++) {
		FIRST[g.Vt[i]].insert(g.Vt[i]);
	}
	// ���һ��������һ�����ս����
	// X->a..., ��a����FIRST(X), ��X->@, ��@Ҳ����FIRST(X)
	// X->Y..., ��FIRST(Y)/@����FIRST(X)
	// X->Y1Y2Y3...Yi...Yk, FIRST(Yi)����@, ���FIRST(Yi)/@����FIRST(X)
	// ������@, ���@Ҳ���� FIRST(X)
	for (int i = 0; i < g.Vn.size(); i++) {
		char c = g.Vn[i];
		for (int j = 0; j < g.P[c].size(); j++) {
			for (int k = 0; k < g.P[c][j].size(); k++) {
				char tem = g.P[c][j][k];
				if (k == 0 && is_Vt(tem)) {
					
				}
			}
		}
	}
}

// ******************************************************************
// ��FOLLOW�� 
// ******************************************************************  
map<char, set<char> > FOLLOW;
void getFOLLOW() {
	
}

// ******************************************************************
// ��Ԥ������� 
// ****************************************************************** 

void getTable() {
	
}

// ******************************************************************
// Ԥ����� 
// ****************************************************************** 
bool analysis() {
	
} 



int main()
{

	FILE * fpin;
   	while (1) {
       	if((fpin=fopen("sy2.txt","r"))!=NULL) break;
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
    puts("\n������ݹ�");
    
    remove_left_recursion(g);
	
//	print_G(g);
	
	puts("\n��ȡ������");
	remove_left_gene(g);
//	print_G(g);
	
	// �������
	 

    return 0;
}
