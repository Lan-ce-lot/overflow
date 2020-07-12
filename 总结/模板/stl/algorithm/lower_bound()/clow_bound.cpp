#include <iostream>
#include <algorithm>

using namespace std;

int seq1[] = {1, 2, 3, 3, 4, 5}, seq2[] = {9, 8, 7, 7, 6, 5};

int main()
{
    //cout<<upper_bound(seq1, seq1+6, 3, greater<int>()) - seq1<<endl;
    //cout<<lower_bound(seq1, seq1+6, 3, greater<int>()) - seq1<<endl;
    cout<<upper_bound(seq1, seq1+6, 3) - seq1<<endl;
    cout<<lower_bound(seq1, seq1+6, 3) - seq1<<endl;

    cout<<endl;

    cout<<upper_bound(seq2, seq2+6, 7, greater<int>()) - seq2<<endl;
    cout<<lower_bound(seq2, seq2+6, 7, greater<int>()) - seq2<<endl;
    cout<<upper_bound(seq2, seq2+6, 7) - seq2<<endl;
    cout<<lower_bound(seq2, seq2+6, 7) - seq2<<endl;
    return 0;
}

