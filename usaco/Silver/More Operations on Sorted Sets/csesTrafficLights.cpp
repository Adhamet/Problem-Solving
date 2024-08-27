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

    int len, n;    cin >> len >> n;
    set<int> lights{0, len};
    multiset<int> dist{len};
    for(int i = 0; i < n; i++) {
        int pos;    cin >> pos;
        auto it1 = lights.upper_bound(pos);
        auto it2 = it1;   it2--;

        dist.erase(dist.find(*it1 - *it2));
        dist.insert(*it1 - pos);   dist.insert(pos - *it2);
        lights.insert(pos);

        auto ans = dist.end();  ans--;
        cout << *ans << " ";
    }

    return 0;
}
