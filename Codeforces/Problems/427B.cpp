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
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	
	int n,t,c,temp;
	cin >> n >> t >> c;
	vector<int> seq;
	seq.push_back(-1);

	for(int i = 0; i < n; i++) {
		cin >> temp;
		if(temp>t) seq.push_back(i);
	}

	seq.push_back(n);
	ll ans = 0;
	for(int i = 1; i < seq.size(); i++) {
		int l = (seq[i] - seq[i-1] - 1);
		ans += max(l-c+1, 0);
	}
	cout << ans;
    return 0;
}