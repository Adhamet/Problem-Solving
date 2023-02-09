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
    char shift;
    string s = "qwertyuiopasdfghjkl;zxcvbnm,./", input, result = "";
    cin >> shift >> input;
    for(int i = 0; i < input.length(); i++)
    {
        int idx = s.find(input[i]);
        if(shift == 'R') result += s[idx-1];
        else result += s[idx+1];
    }
    cout << result;
}

int main()
{
    adhamet

    solve();
    return 0;
}