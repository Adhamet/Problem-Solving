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
    int size,cnt=0;
    string str;
    cin >> size >> str;
    for(int i = 0; i < size; i++)
        str[i] = toupper(str[i]);
    sort(str.begin(),str.end());

    for(int i = 0; i < size; i++)
        if(str[i] != str[i+1]) cnt++;

    if(cnt == 26) cout << "YES";
    else cout << "NO";
}

int main()
{
    adhamet

    solve();
    return 0;
}