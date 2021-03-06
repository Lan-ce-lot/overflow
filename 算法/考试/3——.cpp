#include<bits/stdc++.h>
using namespace std;
vector<int> cnt[26];
string s1[105],s2[105],str,tmp;
int ans[105][105],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s2[i];
	stringstream tmp_;
	getline(cin,tmp);
	while(getline(cin,tmp),tmp!="LAST CASE"){
		tmp_.clear();
		tmp_.str(tmp);
		tmp_>>str;
		for(int i=0;i<26;i++)cnt[i].clear();
		for(int i=0;i<str.size();i++)cnt[str[i]-'A'].push_back(i);
		int index=0;
		while(tmp_>>s1[index]){
			bool flag;
			for (int i=1;!flag&&i<=n;i++)
				if(s1[index]==s2[i]) flag=1;
			if (!flag) index++;
		} 
		memset(ans,0,sizeof ans);
		ans[0][0]=1;
		for (int i=0;i<index;i++)
			for (int j=0;j<s1[i].size();j++)
				for (int k=cnt[s1[i][j]-'a'].size()-1;k>=0;k--)
					ans[i+1][cnt[s1[i][j]-'a'][k]+1]+=
					ans[i][cnt[s1[i][j]-'a'][k]]+ans[i+1][cnt[s1[i][j]-'a'][k]];
		if(ans[index][str.size()])
			cout<<str<<" can be formed in "<<ans[index][str.size()]<<" ways"<<endl;
        else
            cout<<str<<" is not a valid abbreviation"<<endl;
	}
}
