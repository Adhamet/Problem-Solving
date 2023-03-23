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
    set<char> st;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        st.insert(s[i]);
    }

    if(st.size()%2 != 0) cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!";
}
 
int main()
{
    adhamet
 
    solve();
 
    return 0;
}