#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Person
{
    string name;
    string birthday;
};
bool compare(const Person& s1, const Person& s2)//参数为指针所以要用&
{
    if (s1.birthday < s2.birthday)//升序，若改为s1.birthday > s2.birthday,则为降序
        return true;
    else
        return false;
}
int main()
{
    int N;
    vector<Person> man;
    Person temp;
    string compare1 = "2014/09/06";
    string compare2 = "1814/09/06";
    cin >> N;
    for ( int i = 0; i < N; i++)
    {
        cin >> temp.name >> temp.birthday;
        if (temp.birthday <=compare1 && temp.birthday >= compare2)
            man.push_back(temp);
    }
    sort(man.begin(), man.end(), compare); //man.begin()/end()为指针，front(),back()为数据
    if(man.size()==0)
    {
    	puts("0");
		return 0;
	}
    cout <<man.size()<<" " <<man.front().name<<" "<<man.back().name;
    return 0;
}
