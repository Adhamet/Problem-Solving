#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		int len = 1;
		for (int i = 0; i < n - 1; i++) {
			if (i && s[i] == s[i - 1]) len += 1;
			else len = 1;
			cout << 1 + i + 1 - len << " ";
		}

		cout << el;
	}

	return 0;
}
