#include <iostream>
#include<string>
using namespace std;

#define  LENGTH 5          
char ch =' ';
string key[5]={"if","then","else","while","do"};

int Iskey(string c){         //关键字判断
   int i;
   for(i=0;i<LENGTH;i++) {
      if(key[i].compare(c)==0) return 1;
       } 
    return 0;
}

int IsLetter(char c) {        //判断是否为字母
    if(((c<='z')&&(c>='a'))||((c<='Z')&&(c>='A'))) return 1;
    else return 0;
}

int IsLetter1(char c) {        //判断是否为a~f字母,用于十六进制判断
    if(((c<='f')&&(c>='a'))||((c<='F')&&(c>='A'))) return 1;
    else return 0;
}

int IsDigit(char c){          //判断是否为数字
     if(c>='0'&&c<='9') return 1;
     else return 0;
}

void scan(FILE *fpin){
    string arr="";
    while((ch=fgetc(fpin))!=EOF)
	{
         arr="";        
         if(ch==' '||ch=='\t'||ch=='\n'){}     

         else if(IsLetter(ch)||ch=='_')
		 {
			 arr=arr+ch;
			 ch=fgetc(fpin);
                 while(IsLetter(ch)||IsDigit(ch))
				 {
					 if((ch<='Z')&&(ch>='A')) ch=ch+32;   
                             arr=arr+ch;
                    ch=fgetc(fpin);
				 }

                 fseek(fpin,-1L,SEEK_CUR);    
                 if (Iskey(arr)){cout<<"<"<<arr<<",->"<<endl;}     
                 else  cout<<"<0,"<<arr<<">"<<endl;
		 }
         
		 else if(IsDigit(ch))
		 {
			  int flag=0;
				if(ch=='0')
				{
					arr=arr+ch;
					ch=fgetc(fpin);
					if(ch>='0'&&ch<='7'){
				    	while(ch>='0'&&ch<='7')
						{
					    	flag=1;
					    	arr=arr+ch;
						    ch=fgetc(fpin);
						}
					}
					else if(ch=='x'||ch=='X')
					{
						flag=2;
						arr=arr+ch;
					    ch=fgetc(fpin);
						while(IsDigit(ch)||IsLetter1(ch))
						{
                              arr=arr+ch;
							  ch=fgetc(fpin);
						}
					}
					else if(ch==' '||ch==','||ch==';' ){
						cout<<"<1,"<<arr<<">"<<endl;
					}
					fseek(fpin,-1L,SEEK_CUR);
                    if(flag==1)  cout<<"<2,"<<arr<<">"<<endl;
					else if(flag==2)   cout<<"<3,"<<arr<<">"<<endl;
				}

                else  
				{
					arr=arr+ch;
					ch=fgetc(fpin);
					while(IsDigit(ch))
					{
                        arr=arr+ch;
                        ch=fgetc(fpin);
					}
                  fseek(fpin,-1L,SEEK_CUR);
                  cout<<"<1,"<<arr<<">"<<endl;
				}
		 }

         else switch(ch)
		 {          
               case'+':
               case'-' :
               case'*' :
               case'=' :
               case'/' :cout<<"<"<<ch<<",->"<<endl;break;
               case'(' :
               case')' :
               case'[' :
               case']' :               
               case';' :
               case'.' :
               case',' :
               case'{' :
               case'}' :cout<<"<"<<ch<<",->"<<endl;break;
               case':' :{ch=fgetc(fpin);

                        if(ch=='=') cout<<"<"<<":="<<",->"<<endl;
                        else {cout<<"<"<<"::"<<",->"<<endl;;
                               fseek(fpin,-1L,SEEK_CUR);}
                        }break;

              case'>' :{ch=fgetc(fpin);
                         if(ch=='=') cout<<"<"<<">="<<",->"<<endl;
                         if(ch=='>')cout<<"<"<<">>"<<",->"<<endl;
                         else {cout<<"<"<<">"<<",->"<<endl;
                             fseek(fpin,-1L,SEEK_CUR);}
                         }break;

              case'<' :{ch=fgetc(fpin);
                         if(ch=='=')cout<<"<"<<"<="<<",->"<<endl;
                         else if(ch=='<')cout<<"<"<<"<<"<<",->"<<endl;
                         else if(ch=='>') cout<<"<"<<"<>"<<",->"<<endl;
                         else{cout<<"<"<<"<"<<",->"<<endl;
                            fseek(fpin,-1L,SEEK_CUR);}
                        }break;

              default : cout<<"<"<<ch<<",无法识别字符>"<<endl;
		 }
    }
}
int main(){
   FILE * fpin;
   cout<<"词法分析器输出："<<endl;
   for(;;){
       if((fpin=fopen("D:\\work\\C++\\old\\master\\编译原理\\test.txt","r"))!=NULL) break;
       else {
       	cout<<"文件路径错误！请输入文件路径及文件名:"<<endl;return 0;
	   }
     }
   scan(fpin);
   system("pause");
   fclose(fpin);
}
