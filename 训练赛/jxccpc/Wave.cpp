//#include<iostream>
//#include<cmath>
//#include<stdio.h>
//#include<bits/stdc++.h>
//#define LL long long
//#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define fix fixed << setprecision(3)
//using namespace std;
//int mod = 1e9 + 7;
//const int INF = 1e9 + 7;
//const double PI = 45.0 / atan(1.0);
//vector<int> vec[105];
//int main()
//{
//    fio;
//    int n, c, x;
//    cin >> n >> c;
//    for(int i = 1; i <= n; ++i)
//    {
//        cin >> x;
//        vec[x].push_back(i);//下标是数字，内容是位置
//    }
//    int ans = 0;
//    for(int i = 1; i <= c; ++i)
//    {
//        for(int j = 1; j <= c; ++j)
//        {
//            if(i == j)
//                continue;
//            int len1 = vec[i].size();
//            int len2 = vec[j].size();
//            int st1 = 0, st2 = 0, temp = 0, sum = 0;
//            while(1)
//            {
//                while(st1 < len1 && vec[i][st1] < temp)
//                {
//                    st1 += 1;
//                }
//                if(st1 == len1)
//                    break;
//                temp = vec[i][st1];
//                sum += 1;
//                while(st2 < len2 && vec[j][st2] < temp)
//                {
//                    st2 += 1;
//                }
//                if(st2 == len2)
//                    break;
//                sum += 1;
//                temp = vec[j][st2];
//            }
//            ans = max(ans, sum);
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}
#include <iostream>

using namespace std;

int main()

{
	cout<<"                ********"<<endl;
	cout<<"               ************"<<endl;
	cout<<"               ####....#."<<endl;
	cout<<"             #..###.....##...."<<endl;
	cout<<"             ###.......######              ###            ###"<<endl;
	cout<<"                ...........               #...#          #...#"<<endl;
	cout<<"               ##*#######                 #.#.#          #.#.#"<<endl;
	cout<<"            ####*******######             #.#.#          #.#.#"<<endl;
	cout<<"           ...#***.****.*###....          #...#          #...#"<<endl;
	cout<<"           ....**********##.....           ###            ###"<<endl;
	cout<<"           ....****    *****...."<<endl;
	cout<<"             ####        ####"<<endl;
	cout<<"           ######        ######"<<endl;
	cout<<"##############################################################"<<endl;
	cout<<"#...#......#.##...#......#.##...#......#.##------------------#"<<endl;
	cout<<"###########################################------------------#"<<endl;
	cout<<"#..#....#....##..#....#....##..#....#....#####################"<<endl;
	cout<<"##########################################    #----------#"<<endl;
	cout<<"#.....#......##.....#......##.....#......#    #----------#"<<endl;
	cout<<"##########################################    #----------#"<<endl;
	cout<<"#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#"<<endl;
	cout<<"##########################################    ############"<<endl;


return 0;

}
