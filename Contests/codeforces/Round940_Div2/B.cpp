#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int n,k,mx=0;
vector<int> ans;
void solve(int num, int sum, vector<int> vec) {
	if(sum > k) return;

	if(sum == k && num == n) {
		int a = 0;
		for(auto ele: vec)
			a |= ele;

		if(__builtin_popcount(a) > mx) {
			mx = __builtin_popcount(a);
			ans = vec;
		}
		return;
	}

	if(num <= n) {
		vec.push_back(num);
		solve(num+1, sum+num, vec);
		vec.pop_back();
		solve(num+1, sum, vec);
	}
}

int main()
{
	adhamet;
	int t;	cin >> t;
	while(t--) {
		cin >> n >> k;
		ans.clear();
		mx = 0;

		vector<int> a;
		solve(1, 0, {});

		for(int a: ans) cout << a << " ";
	}
	
    return 0;
}