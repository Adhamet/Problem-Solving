#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i64 sm = 2;
	function<void(int,int)> fib = [&](int fs, int sc) -> void { 
		int th = fs + sc;
		if (th > 4000000) return;
		if (th % 2 == 0) sm += i64(th);
		fib(sc, th);
	};

	fib(1, 2);
	cout << sm;

	return 0;
}
