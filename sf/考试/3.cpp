#include<bits/stdc++.h>
using namespace std;
//https://www.luogu.com.cn/problem/solution/P1624
string com[201] , no[201] , mod;
int ans[201][201];
vector < int > pot[26];

int main(){
    int N;
    cin >> N;
    for(int i = 1 ; i <= N ; i++)
        cin >> no[i];
    string s;
    stringstream ss;
    getline(cin , s);
    while(getline(cin , s) && s != "LAST CASE"){
    //注意"LAST CASE\r"的判断！
		ss.clear();
        //清空输入输出流
        ss.str(s);
        //将输入输出流ss赋值为s
        ss >> mod;
        //这样子可以用stringstream模拟cin操作！
        for(int i = 0 ; i < 26 ; i++)
            pot[i].clear();
        for(int i = 0 ; i < mod.size() ; i++)
            pot[mod[i] - 'A'].push_back(i);
        int dir = 0;
        while(ss >> com[dir]){
            bool f = 0;
            for(int i = 1 ; !f && i <= N ; i++)
                if(com[dir] == no[i])
                    f = 1;
            if(!f)
                dir++;
        }
        memset(ans, 0, sizeof ans);
        ans[0][0] = 1;
        for(int i = 0 ; i < dir ; i++)
            for(int j = 0 ; j < com[i].size(); j++)
                for(int k = pot[com[i][j] - 'a'].size() - 1 ; k >= 0 ; k--)
                    ans[i + 1][pot[com[i][j] - 'a'][k] + 1] += ans[i][pot[com[i][j] - 'a'][k]] + ans[i + 1][pot[com[i][j] - 'a'][k]];
        if(ans[dir][mod.size()])
            cout << mod << " can be formed in " << ans[dir][mod.size()] << " ways" << endl;
        else
            cout << mod << " is not a valid abbreviation" << endl;
    }
    return 0;
}
