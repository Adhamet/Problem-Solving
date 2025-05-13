#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; cin >> s;

    int n = (int)s.size();
    vector<long long> freq(26, 0);
    vector<vector<long long>> pairFreq(26, vector<long long>(26, 0));

    for (int i = 0; i < n; ++i) {
        int ch1 = s[i] - 'a';
        for (int ch2 = 0; ch2 < 26; ++ch2)
            pairFreq[ch2][ch1] += freq[ch2];
        freq[ch1]++;
    }

    long long res = *max_element(freq.begin(), freq.end());
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            res = max(res, pairFreq[i][j]);
    return cout << res, 0;
}

