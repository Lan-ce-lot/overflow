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
// 消除左递归 
// ****************************************************************** 
char get_Vn(string str) {// 用于消除左递归 
	for (int i = 0; i < 26; i++) {
		char c = (i + 'A');
		if (!exitV(str, c)) return c;
	}
	return ' ';
}

bool check_Vn_repeat(string s, vector<string> str) { // 检查产生式右半部是否存在 
	for (auto it : str) {
		if (s == it) {
			return true;
		}
	}
	return false;
}

void simplify(grammar &g) {
	map<char, string> to; // 记录char非终结符能到达的非终结符
	for (int i = g.Vn.size() - 1; i >= 0; i--) {
		for (int j = g.Vn.size() - 1; j >= 0; j--) {
			char c = g.Vn[j];
			for (int k = 0; k < g.P[c].size(); k++) {
				for (int z = 0; z < g.P[c][k].size(); z++) {
					if (g.P[c][k][z] >= 'A' && g.P[c][k][z] <= 'Z' && g.P[c][k][z] != c && !exitV(to[c], g.P[c][k][z])) {
						to[c] += g.P[c][k][z];
					}
				}
			}
		}
	}
	string tem_Vn = "", tem_Vt = "";
	for (int i = 0; i < g.Vn.size(); i++) {
		if (g.Vn[i] != g.S && !exitV(to[g.S], g.Vn[i])) {
			g.P.erase(g.Vn[i]);
		} else {
			tem_Vn += g.Vn[i];
		}
	}
	g.Vn = tem_Vn;
	for (int i = 0; i < g.Vn.size(); i++) {
		char c = g.Vn[i];
		for (int j = 0; j < g.P[c].size(); j++) {
			for (int k = 0; k < g.P[c][j].size(); k++) {
				if (is_Vt(g.P[c][j][k]) && exitV(tem_Vt, g.P[c][j][k])) {
					tem_Vt += g.P[c][j][k];
				}
			}
		}
	}
//	print_G(g);
}

void remove_left_recursion(grammar &g) {
//	bool flag[N];
//	memset(flag, 0, sizeof flag);
	// 替换
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
		// 消除直接左递归 
		// 这里只考虑S开头的产生式的情况 
		for (int j = 0; j < g.P[g.S].size(); j++) {
			if (g.P[g.S][j][0] == g.S) {
				char new_c = get_Vn(g.Vn);
				g.Vn += new_c;
//				g.P[g.S][j] = g.P[g.S][j].substr(1, g.P[g.S][j].size() - 1) + new_c;
				for (int k = 0; k < g.P[g.S].size(); k++) {
					if (k != j) {
						g.P[g.S][k] += new_c;
					}
				} 
				
				g.P[new_c].push_back(g.P[g.S][j].substr(1, g.P[g.S][j].size() - 1) + new_c);
				g.P[new_c].push_back("@");
				if (!exitV(g.Vt, '@')) {
					g.Vt += "@";
				}
				g.P[g.S].erase(g.P[g.S].begin());
			}
		} 
//		
		
	}	
	
	print_G(g);
	//
	// 化简 
	//
	simplify(g);
} 

// ******************************************************************
// 消除回溯 
// 提取左因子
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
				g.P[c].push_back(s);
			}
		}
	}
	simplify(g);
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

int main()
{

	FILE * fpin;
   	while (1) {
       	if((fpin=fopen("D:\\work\\C++\\old\\master\\编译原理\\t.txt","r"))!=NULL) break;
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
    puts("\n消除左递归");
    remove_left_recursion(g);
	
	print_G(g);
	
	puts("\n提取左因子");
	remove_left_gene(g);
	print_G(g);
    return 0;
}
