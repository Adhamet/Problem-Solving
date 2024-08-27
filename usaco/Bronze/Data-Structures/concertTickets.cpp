// CSES - 1091
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int n,m,h,t;	cin >> n >> m;
	multiset<int> tickets;
	for(int i = 0; i < n; i++) {
		cin >> h;
		tickets.insert(h);
	}
	for(int i = 0; i < m; i++) {
		cin >> t;
		auto it = tickets.upper_bound(t);
		if(it == tickets.begin())
			cout << -1 << el;
		else {
			cout << *(--it) << el;
			tickets.erase(it);
		}
	}
	
	return 0;
}
