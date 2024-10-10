#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int n;  cin >> n;
    set<ll> pts;
    map<ll,int> freq;
    for(int i = 0; i < n; i++) {
        ll l,r;     cin >> l >> r;
        freq[l]++;  freq[r+1]--;
        pts.insert(l);  pts.insert(r+1);
    }

    int layers = freq[*pts.begin()];
    auto it = next(pts.begin());
    vll covered(n+1);
    while( it != pts.end() ) {
        covered[layers] += (*it - *prev(it));
        layers += freq[*it];    it++;
    }
    for(int i = 1; i < n; i++) cout << covered[i] << " ";
    cout << covered[n] << el;

    return 0;
}
