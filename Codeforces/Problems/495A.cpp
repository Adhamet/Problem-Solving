#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

int main()
{
    adhamet
    
    map<int,int> digital_counter = { {8,1},{9,2},{0,2},{6,2},{2,2},
                                         {3,3},{4,3},{5,4},{7,5},{1,7} };
    int cntr = 1;
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
        cntr *= digital_counter[s[i] - '0'];
    cout << cntr;

    return 0;
}   
