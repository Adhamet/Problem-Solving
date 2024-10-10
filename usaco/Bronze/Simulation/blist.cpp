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

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);	
	}
}

const int MAX_TIME = 1000;
int main()
{
    adhamet;
    setIO("blist");

	int n;	cin >> n;
	vector<int> change(MAX_TIME + 1);
	for (int c = 0; c < n; c++) {
		int start, end, bkts;
		cin >> start >> end >> bkts;

		change[start] += bkts;
		change[end] -= bkts;
	}

	int max_buckets = 0, curr_buckets = 0;
	for (int t = 0; t < MAX_TIME; t++) {
		curr_buckets += change[t];
		max_buckets = max(max_buckets, curr_buckets);
	}
	cout << max_buckets << el;

    return 0;
}