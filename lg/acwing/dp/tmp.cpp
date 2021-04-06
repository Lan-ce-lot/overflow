#include<bits/stdc++.h>
using namespace std;
#define MAX 100
vector<set<string> > test;
int main(){
	set<string> st;
	st.insert("xiexie");
	st.insert("xiexia");
	test.push_back(st);
	for(vector<set<string> >::iterator  it = test.begin() ; it !=test.end() ; it++){
        for (set<string>::iterator i = it->begin(); i != it->end(); i++) {
            cout << *i << endl;
        }
	}
	return 0;
}