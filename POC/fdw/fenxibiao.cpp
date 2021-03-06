#include <iostream>
#include <string.h>
#include "zhan.h" 
#include "cifa.h"
using namespace std;

string AllVN = "EXYTF";
string AllVT = "i()+*";

//ÅÐ¶Ï·ûºÅÊÇ·ñÎªÖÕ½á·û 
bool InVT(char str){
	int i = 0;
	while(AllVT[i]){
		if(str == AllVT[i])
		    return true;
		i++;
	}
	return false;
}

//·ÖÎö±íº¯Êý 
string FenXiBiao(char VN,char VT){
	if(VN == 'E'){
		if(VT == 'i' || VT == '(')
			return "TX";
		else
		    return "null";
	}
	else if(VN == 'X'){
		if(VT == '+')
	        return "+TX";
	    else if(VT == ')' || VT =='#')
	        return "@";
	    else
	        return "null";
	}
	else if(VN == 'T'){
		if(VT == 'i' || VT == '(')
		    return "FY";
		else
		    return "null";
	}
	else if(VN == 'Y'){
		if(VT == '+' || VT == ')' || VT == '#')
		    return "@";
		else if(VT == '*')
		    return "*FY";
	}
	else if(VN == 'F'){
		if(VT == 'i')
	        return "i";
	    else if(VT == '(')
	        return "(E)";
	    else
	        return "null";
	}
	else
	    return "null";
} 

//×Ö·û´®µ¹ÐòÈëÕ» 
bool SDaoXuPush(SqStack &S,string str){
	int i = 0;
	while(str[i])
		i++;   
	for(i--;i >= 0;i--)
	    Push(S,str[i]);
} 

int main(){
	SqStack S1,S2;
	InitStack(S1);
	InitStack(S2);
	string BDShi; 
	string TuiDao;
	if((fp=fopen("jz.txt","r"))==NULL){
		cout<<"file can not open!";
		exit(0);
	}
	while(!feof(fp)){
		do{
			ClearStrToken();
	        GetChar(fp); 
     	    GetBC(fp);
     	    if(!feof(fp))
	        ProcessS();
		}while(ch != ';');
		BDShi = getBiaoDaShi();
		Push(S1,'#');
		SDaoXuPush(S1,BDShi);
		
		Push(S2,'#');
		Push(S2,'E');
		char X,a;
		Pop(S1,a);
		bool flag = true;
		while(flag){
			
			Pop(S2,X);
			
			if(InVT(X)){
				if(X == a)
				  Pop(S1,a);
				else{
					cout<<"´íÎó";
					break;
				} 
				     
			}
			else if(X == '#'){
				if(X == a){
					flag = false;
					cout<<"ÕýÈ·"; 
				}
				   
				else{
					cout<<"´íÎó";
					break;
				} 
			}
			else if(FenXiBiao(X,a) != "null"){
				TuiDao = FenXiBiao(X,a);
				if(TuiDao != "@")
				  SDaoXuPush(S2,TuiDao);
			}
			else{
					cout<<"´íÎó";
					break;
				}  
		}	
		ClearBiaoDaShi();
		ClearStack(S1);
		ClearStack(S2);   
	}

	
	
}
