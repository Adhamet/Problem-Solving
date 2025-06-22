#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
    vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int mxRgt = 0;
    for (int i=0, j=0; i < n; i++) {
        while (j < n && b[j] <= a[i]) j++;
        if (j < n) {
            mxRgt++;
            j++;
        }
    }
	int mnLft = n - mxRgt;

    int mxLft = 0;
    for (int i=n-1, j=n-1; i >= 0; i--) {
        while (j >= 0 && b[j] >= a[i]) j--;
        if (j >= 0) {
            mxLft++;
            j--;
        }
    }

    cout << (mxLft - mnLft + 1) << el;
    for (int x = mnLft; x <= mxLft; ++x) cout << x << ' ';
    return 0;
}
