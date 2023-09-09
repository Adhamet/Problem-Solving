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

    string s;
    cin >> s;

    int cnt=0,total=0;
    for(int i = 0; i < s.size(); i++) if (s[i] == '(')
        cnt++;
    else if (cnt != 0) {
        cnt--;
        total+=2;
    }
    cout << total;
    
    return 0;
}
