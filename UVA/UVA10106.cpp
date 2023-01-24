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
const int MXN = 501;

void solve()
{
    string s1,s2;
    while(cin >> s1)
    {
        cin >> s2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int a[MXN];
        memset(a, 0, sizeof(a));
        for(int i = 0; i < s1.length(); i++) {
            for(int j = 0; j < s2.length(); j++) {
                a[i+j] += (s1[i] - '0') * (s2[j] - '0');
            }
        }

        for(int i = 0; i < MXN - 1; i++) {
            a[i+1] += a[i] / 10;
            a[i] %= 10;
        }
        int i = MXN - 1;
        while( i > 0 && a[i] == 0 ) i--;
        for(; i>=0; i--) cout << a[i];
        cout << endl;
    }
}

int main()
{
    adhamet 
    
    solve();
    return 0;
}