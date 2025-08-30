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

	int t;	cin >> t;
	while (t--) {
		i64 n, m, k;	cin >> n >> m >> k;
		vector<i64> a(k);
		for (int i = 0; i < k; ++i) cin >> a[i];
		i64 need = k;
		bool acc = true;
		unordered_set<int, SplitMix64> out;
		for (int i = 0; i < k; ++i) {
			out.insert(a[i]);
			while (out.count(need)) out.erase(need), need--;
			if ((int)out.size() > n * m - 4) { acc = false; break; }
		}
		cout << (acc? "YA": "TIDAK") << '\n';
	}

	return 0;
}
