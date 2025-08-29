#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'
#define debug(...)
/*#define debug(...) cerr << __VA_ARGS__ << el;*/

bool nextString(string &s) {
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != 'z') {
            s[i]++;
            return true;
        }
        s[i] = 'a';
    }
    return false;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		string s;	cin >> s;
		
		for (int len = 1; len <= 3; ++len) {
			set<string> st;
			for (int i = 0; i + len <= n; ++i)
				st.insert(s.substr(i, len));

			string mn(len, 'a');
			while (true) {
				if (!st.count(mn)) {
					cout << mn << el;
					break;
				}
				if (!nextString(mn)) break;
			}

			if (!st.count(mn)) break;
		}
	}

	return 0;
}
