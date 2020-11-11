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

// �жϹؼ���
bool IsKey(string c) {
	for (int i = 0; i < KEY_LEN; i++) {
		if (key[i] == c) {
			return true;
		}
	}
	return false;
}

// �ж��Ƿ�Ϊ��ĸ
bool IsLetter(char c) {
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

//�ж��Ƿ�Ϊa~f��ĸ
bool IsA_F(char c) {
	return c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F';
}

//�ж��Ƿ�Ϊ����
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
			} 
//			else if (IsSymbols(ch)) {
//				cout << '<' << ch << " , ->" << endl;
//			} 
			else switch(ch) {          
               	case'+' :
               	case'-' :
               	case'*' :
               	case'=' :
               	case'/' :
               	case'(' :
               	case')' :
               	case'[' :
               	case']' :               
               	case';' :
               	case'.' :
               	case',' :
               	case'{' :
               	case'}' :cout<<"<"<<ch<<" , ->"<<endl;break;
               	case':' :{ch=fgetc(fpin);
                        if(ch=='=') cout<<"<"<<":="<<" , ->"<<endl;
                        else {cout<<"<"<<"::"<<" , ->"<<endl;;
                               fseek(fpin,-1L,SEEK_CUR);}
                        }break;

              	case'>' :{ch=fgetc(fpin);
                        if(ch=='=') cout<<"<"<<">="<<" , ->"<<endl;
                        if(ch=='>')cout<<"<"<<">>"<<" , ->"<<endl;
                        else {cout<<"<"<<">"<<" , ->"<<endl;
                            fseek(fpin,-1L,SEEK_CUR);}
                        }break;
                         
              	case'<' :{ch=fgetc(fpin);
                        if(ch=='=')cout<<"<"<<"<="<<" , ->"<<endl;
                    	else if(ch=='<')cout<<"<"<<"<<"<<" , ->"<<endl;
                        else if(ch=='>') cout<<"<"<<"<>"<<" , ->"<<endl;
                        else {cout<<"<"<<"<"<<" , ->"<<endl;
                            fseek(fpin,-1L,SEEK_CUR);}
                        }break;
              	default : cout<<"<"<<ch<<",�޷�ʶ����ַ�>"<<endl;
		 	}
		}
	}
}

int main()
{
   	FILE * fpin;
   	cout<<"�ʷ������������"<<endl;
   	while (1) {
       	if((fpin=fopen("test.txt","r"))!=NULL) break;
       	else cout<<"�ļ�·������\n";return 0;
    }
    printf("0.��ʶ�� 1.ʮ���� 2.�˽��� 3:ʮ������\n");
   	scan(fpin);
//   system("pause");
   	fclose(fpin);
    return 0;
}
