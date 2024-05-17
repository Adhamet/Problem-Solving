#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
	adhamet;

	int t;	cin >> t;
	while(t--) {
		int n;	cin >> n;
		int length;
		map<int,int> freq;
		for(int i = 0; i < n; i++) {
			cin >> length;
			freq[length]++;
		}

		ll ans = 0;
		for(auto sticks: freq) {
			ans+=sticks.second/3;
		}
		printf("%d\n",ans);
	}
	
    return 0;
}