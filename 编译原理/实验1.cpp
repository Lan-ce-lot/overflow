#include <algorithm>
#include <iostream>

using namespace std;

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

void scan(FILE * fpin) {
	char ch;
	while ((ch=fgetc(fpin))!=EOF) {
		string tem="";
		if (ch != ' ' && ch != '\t' && ch != '\n') {
			
			if (IsLetter(ch) || ch == '_') { 	
				tem += ch;
				while ((ch=fgetc(fpin))!=EOF && (IsLetter(ch) || ch == '_' || IsDigit(ch))) {
					tem += ch;
				}
				fseek(fpin, -1L, SEEK_CUR);
				if (IsKey(tem)) cout << '<' << tem << " , " << "->" << endl;
				else cout << '<' << "0" << " , " << tem << '>' << endl;
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
   	while (1) {
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
