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

void solve()
{
    int chars;
    cin >> chars;
    string str;
    cin >> str;
    map<char,int> m1,m2;
    for(auto c: str) { m2[c]++; }
    int ms = m2.size();
    for(auto c: str)
    {
        m1[c]++;
        m2[c]--;
        if(m2[c]==0) { m2.erase(c); }
        int temp = m1.size()+m2.size();
        ms = max(ms,temp);
    }
    cout << ms << endl;

}

int main()
{
    adhamet
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}