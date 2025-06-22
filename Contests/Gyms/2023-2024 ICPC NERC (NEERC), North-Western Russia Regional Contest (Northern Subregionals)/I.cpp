#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 long long
#define el '\n'

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	auto take = [&]() {
		int x; 
		cin >> x;
		if (x == n) exit(0);
		return x;
	};

	int qrys = 0;
	auto ask = [&](int a, int b) {
		++qrys;
		assert(qrys <= 2500);
		cout << a << ' ' << b << el;
		cout.flush();
	};

	auto gray = [&](int k) {
		int num = 1 << k;
		vector<int> res;
		res.reserve(num);
		for (int i = 0; i < num; ++i)
			res.push_back(i ^ (i >> 1));
		return res;
	};

	take();

	for (int pos = 1; pos <= n; ++pos) {
		ask(pos, pos);
		int x = take();
		ask(pos, pos);
		int nx = take();
		if (nx == x + 1) {
			ask(pos, pos);
			take();
		}
	}

	for (int pos = 1; pos <= n; ++pos) {
		ask(pos, pos);
		int x = take();
		ask(pos, pos);
		int nx = take();

		if (nx == x - 1) {
			ask(pos, pos);
			take();
			continue;
		} else if (nx == x + 1) continue;

		vector<int> cg = gray(n - pos);
		for (int i = 1; i < (int)cg.size(); ++i) {
			int offset = __lg((cg[i] ^ cg[i - 1]));
			ask(pos, pos + offset + 1);
			int a = take();
			ask(pos, pos);
			int b = take();

			if (b == a - 1) {
				ask(pos, pos);
				take();
				break;
			} else if (b == a + 1) break;
		}
	}

	return 0;
}
