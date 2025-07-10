#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int MXN = 1e6+5;
	const i64 P1 = 37, M1 = 1e9+7;
	const i64 P2 = 39, M2 = 1e9+9;

	vector<i64> powa1(MXN, 0), powa2(MXN, 0);
	powa1[0] = powa2[0] = 1;
	for (int i = 1; i < MXN; ++i) {
		powa1[i] = powa1[i-1] * P1 % M1;
		powa2[i] = powa2[i-1] * P2 % M2;
	}

	int t;	cin >> t;
	while (t--) {
		string s;	cin >> s;
		int n = (int)s.size();

		vector<i64> h1(n+1, 0), h2(n+1, 0);
		for (int i = 0; i < n; ++i) {
			h1[i+1] = (h1[i] + (s[i]-'a'+1) * powa1[i]) % M1;
			h2[i+1] = (h2[i] + (s[i]-'a'+1) * powa2[i]) % M2;
		}

		vector<int> freqCh(26, 0);
		for (auto &ch: s) freqCh[ch-'a']++;
		int mxFreq = *max_element(freqCh.begin(), freqCh.end());
		char bigCh = 'a';
		for (int ch = 25; ch >= 0; --ch) if (freqCh[ch]==mxFreq) {
			bigCh = char(ch+'a');
			break;
		}

		auto calc = [&](int len) {
			int cnt = 0, idx;
			pair<i64, i64> only;
			for (int i = 0; i < n; i++) if (s[i] == bigCh) {
				i64 currH1 = (h1[i+len] - h1[i] + M1) % M1;
				i64 currH2 = (h2[i+len] - h2[i] + M2) % M2;
				currH1 = currH1 * powa1[n-i-1] % M1;
				currH2 = currH2 * powa2[n-i-1] % M2;
				only = {currH1, currH2};
				break;
			}

			for (int i = 0; i + len <= n; ++i) {
				if (s[i] != bigCh) continue;
				i64 currH1 = (h1[i+len] - h1[i] + M1) % M1;
				i64 currH2 = (h2[i+len] - h2[i] + M2) % M2;
				currH1 = currH1 * powa1[n-i-1] % M1;
				currH2 = currH2 * powa2[n-i-1] % M2;
				pair<i64, i64> currH = {currH1, currH2};
				if(currH != only) return false;
				cnt++;
			}

			return cnt == mxFreq;
		};

		int l = 1, r = n, ans = 1;
		while (l <= r) {
			int md = (l + r) >> 1;
			if (calc(md)) {
				ans = md;
				l = md + 1;
			} else r = md - 1;
		}

		for (int i = 0; i < n; i++) if(s[i] == bigCh) { 
			cout << s.substr(i, ans) << el;
			break;
		}
	}

	return 0;
}
