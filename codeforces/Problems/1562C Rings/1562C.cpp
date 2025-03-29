#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

		bool acc = false;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				acc = true;
				if (i >= n / 2) {
					cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << el;
				} else cout << i + 2 << ' ' << n << ' ' << i + 1 << ' ' << n << el;
				break;
			}
		}

		if (!acc) cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << el;
	}

    return 0;
}
