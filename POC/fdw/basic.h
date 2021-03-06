#include <iostream>
#include <string.h>
using namespace std;
char ch;
char strToken[20];
char baoliuzi[7][10] = {" ","if","then","else","while","do"};
char yunsuanfu[11] = "+-*/><=();";
void GetChar(FILE *fp){
	if(!feof(fp))
	    ch = fgetc(fp);
      
    else
     ch = ' ';
} 
void GetBC(FILE *fp){
	while(ch == ' ' || ch == 10){
		GetChar(fp);
	}
}
void Concat(int i){
	strToken[i] = ch;
}
bool IsLetter(){
	if('A' <= ch && ch <= 'Z' || 'a' <= ch && ch<= 'z')
	  return true;
	else
	  return false;
}
bool IsDigit(){
	if('0' <= ch && ch <= '9')
	  return true;
	else
	  return false;
}
int Reserve(){
	for(int j = 1;j<6;j++){
		if(strcmp(strToken,baoliuzi[j]) == 0)
	        return j;
	}
	return 0;
}
void Retract(FILE *fp){
	if(!feof(fp)){
		fseek(fp,-1L,1);
	    ch = ' ';
	}

}
void ClearStrToken(){
	for(int i = 0;strToken[i] != '\0';i++){
		strToken[i] = '\0';
	}
}
string GetBaoLiuZi(int k){
	return baoliuzi[k];
} 
string GetStrToken(){
	return strToken;
}
bool IsYunSuanFu(){
	for(int i = 0;yunsuanfu[i] != '\0';i++)
	  if(ch == yunsuanfu[i])
	    return true;
	return false;
}

