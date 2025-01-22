#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using ld = long double;
#define Youssef() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
#define unmap unordered_map
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvl vector<vll>
#define si(x) ll(x.size())
#define For(i, j, n) for(ll i = j; i < n; i++)
#define rFor(i, j, n) for(ll i = j; i >= n; i--)
#define read(a) For(i, 0, si(a)) cin >> a[i];
#define readd(a) For(i, 0, si(a)) For(j, 0, si(a[0])) cin >> a[i][j];
#define print(a) For(j, 0, si(a)) cout << a[j] << (j < si(a)-1 ? " " : ""); cout << endl;
#define fi first
#define se second


int main()
{
    Youssef();
    // freopen("lineup.out", "w", stdout);
    // freopen("lineup.in", "r", stdin);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n, k; cin >> n >> k;
        vi a(n); read(a);
        unmap<int, int> freq;
        For(i, 0, n) freq[a[i]]++;
        vi g, b;
        int ans = 0;
        for(auto &i : freq)
        {
            if(k % 2 == 0 && k / 2 == i.fi)
            {
                ans += i.se / 2;
            }
            else if(freq.find(k - i.fi) != freq.end())
            {
                ans += min(i.se, freq[k-i.fi]);
                freq[i.fi] -= min(i.se, freq[k-i.fi]);
                freq[k - i.fi] -= min(i.se, freq[k-i.fi]);
            }
        }
        cout << ans << endl;
    }
}
