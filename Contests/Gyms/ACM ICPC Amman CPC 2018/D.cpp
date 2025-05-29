#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		i64 n, m; cin >> n >> m;
		if (n%2==0 && m%2==0) {
			cout << 2*(n/2) + 2*((n+2)/2) << el;
		} else if (n%2==1 && m%2==1) {
			cout << ((n-1)/2)*((n+1)/2) + ((n+1)/2)*((n+1)/2) << el;
		} else cout << 2 * (max(n,m) + 1) << el;
	}

	return 0;
}

/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*#define i32 int32_t*/
/*#define i64 int64_t*/
/*#define el '\n'*/
/**/
/*int32_t main() {*/
/*	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);*/
/**/
/*	int t; cin >> t;*/
/*	while (t--) {*/
/*		i64 n, m; cin >> n >> m;*/
/*		i64 x = (n+1)*m, y = n*(m+1);*/
/*		x /= 2, y /= 2;*/
/*		cout << min(x, y) << el;*/
/*	}*/
/**/
/*	return 0;*/
/*}*/
