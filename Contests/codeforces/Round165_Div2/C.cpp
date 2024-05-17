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
	int t;	cin >> t;
	while(t--) {

		int n,k;	cin >> n >> k;
		vector<pair<int,int>> input(n);
		vector<pair<int,int>> asc(n), desc(n);
		vector<int> output(n);

		for(int i = 0; i < n; i++) {
			cin>>input[i].first;
			input[i].second = i;
		}
		asc, desc = input;

		sort(asc.begin(),asc.end()); // smallest
		sort(desc.rbegin(), desc.rend()); // greatest;
		for(int i = 0; i<n/2; i++) {
			if(desc[i].second - asc[i].second <= k) {
				output[i] = asc[i].first;
				continue;
			}
		}

		long long sum = 0;
		for(auto ele: output) sum+=ele;
		cout << sum << el;
	}
	return 0;
}