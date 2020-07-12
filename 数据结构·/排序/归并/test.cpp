#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
using namespace std;
int main()
{
    vector<int>vecIntA;
    vecIntA.push_back(1);
    vecIntA.push_back(3);
    vecIntA.push_back(5);
    vecIntA.push_back(7);
    vecIntA.push_back(9);
    vector<int>vecIntB;
    vecIntB.push_back(2);
    vecIntB.push_back(4);
    vecIntB.push_back(6);
    vecIntB.push_back(8);
    vector<int>vecIntC;
    vecIntC.resize(9);
    merge(vecIntA.begin(), vecIntA.end(), vecIntB.begin(), vecIntB.end(), vecIntC.begin());
    for(size_t i = 0; i < vecIntC.size(); i++)
    {
        cout << vecIntC[i] << " ";
    }
    cin.get();
    return 0;
}
