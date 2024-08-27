#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    freopen("outofplace.in","r",stdin);
    freopen("outofplace.out","w",stdout);
    adhamet;

    int n;  cin >> n;
    vector<int> cows(n);    for(int &c: cows) cin >> c;
    vector<int> s_cows(cows);   sort(s_cows.begin(), s_cows.end());
    int moves = 0;
    for(int i = 0; i < n; i++) if(cows[i] != s_cows[i]) moves++;
    cout << moves - 1 << el;

    return 0;
}
