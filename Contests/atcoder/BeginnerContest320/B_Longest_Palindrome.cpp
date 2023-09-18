#include <iostream>
#include <string>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using pd = pair<ld,ld>;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    string s;
    cin >> s;
    int n = (int) s.size();
    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            string w = s.substr(i, j-i+1);
            string u(w.rbegin(), w.rend());
            if (u == w) ans = max(ans, (int) w.size());
        }
    }
    cout << ans;

    return 0;
}
