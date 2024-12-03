#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		map<int, int> freq;
		for (int i = 0; i < n; i++) freq[s[i] - 'a'] += 1;

		int mxRep = 0, mnRep = 15;
		char mxChar, mnChar;
		for (auto itr: freq) {
			if (mxRep < itr.second) {
				mxRep = itr.second;
				mxChar = (itr.first + 'a');
			}

			if (mnRep > itr.second) {
				mnRep = itr.second;
				mnChar = (itr.first + 'a');
			}
		}

		bool equals = (mnRep == mxRep);
		for (int i = 0; i < n; i++) {
			if (equals) {
				if (s[i] != mxChar) {
					s[i] = mxChar;
					break;
				}
			} else {
				if (s[i] == mnChar) {
					s[i] = mxChar;
					break;
				}
			}
		}

		cout << s << el;
	}

	return 0;
}
