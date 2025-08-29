#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

struct SplitMix64 {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int q;	cin >> q;
	unordered_set<i64, SplitMix64> st;
	unordered_map<i64, i64, SplitMix64> nxtVal;
	while (q--) {
		char type;	cin >> type;
		if (type == '+') {
			i64 x; cin >> x;
			st.insert(x);
		} else {
			i64 k;	cin >> k;
			if (!nxtVal.count(k)) nxtVal[k] = k;
			while (st.count(nxtVal[k])) nxtVal[k] += k;
			cout << nxtVal[k] << '\n';
		}
	}

	return 0;
}

