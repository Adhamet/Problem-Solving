#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int n, ans = 0;     cin >> n;
    string s;   cin >> s;
    for(int i = n-1; i>=1; i-=2) {
        if(s[i] == s[i-1]) continue;
        if(s[i] == 'G' && ans%2==1) ans++;
        if(s[i] == 'H' && ans%2==0) ans++;
    }
    cout << ans << el;
    return 0;
}
