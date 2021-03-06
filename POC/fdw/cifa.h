#include "basic.h" 
#include <string>
FILE *fp;
int i;
string BiaoDaShi;

void ProcessA(){
	Concat(i);
	i++;
	GetChar(fp);
	if(IsLetter()||IsDigit()||ch=='_')	
		ProcessA();
	else{
		Retract(fp);
		int m = Reserve();
		if(m != 0)
			cout<<"<"<<GetBaoLiuZi(m)<<",->"<<endl;
		else
			BiaoDaShi += 'i';
	}
}
void ProcessB(){
	Concat(i);
	i++;
	GetChar(fp);
	if(IsDigit())
		ProcessB();
	else{
		Retract(fp);
		BiaoDaShi += 'i';
	} 	 
}
void ProcessD(){
	Concat(i);
	i++;
	GetChar(fp);
	if(ch >= '0' && ch <= '7')
	  ProcessD();
	else{
		Retract(fp);
		BiaoDaShi += 'i';
	}
}
void ProcessE(){
	Concat(i);
	i++;
	GetChar(fp);
	if(IsDigit() || ch >= 'a' && ch <= 'f')
	  ProcessE();
	else{
		Retract(fp);
		BiaoDaShi += 'i';
	}
}
void ProcessC(){
	Concat(i);
	i++;
	GetChar(fp);
	if(ch >= '1' && ch <='7')
	  ProcessD();
	else if(ch == 'x')
	  ProcessE();
	else{
		Retract(fp);
		BiaoDaShi += 'i';
	}
} 
void ProcessS(){
	i = 0;
	if(IsLetter())
	  ProcessA();
	else if(IsDigit() && ch != '0')
	  ProcessB();
	else if(ch == '0')
	  ProcessC();
	else if(IsYunSuanFu()){
	    BiaoDaShi += ch;
	}
	  
	else
	  cout<<"ÊäÈë´íÎó:"<<ch<<endl; 
}

string getBiaoDaShi(){
	BiaoDaShi = BiaoDaShi.substr(0,BiaoDaShi.length()-1);
	return BiaoDaShi;
}

bool ClearBiaoDaShi(){
	BiaoDaShi = "";
	return true;
}
