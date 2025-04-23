#include <bits/stdc++.h>
using namespace std;

const int MAX_S = 1e7;

vector<int> spf(MAX_S + 1);
vector<long long> divsCnt(MAX_S + 1);
vector<long long> pref(MAX_S + 1);

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i*i <= MAX_S; ++i) if (spf[i] == i) {
        for (int j = i*i; j <= MAX_S; j += i) if (spf[j] == j) {
 			spf[j] = i;
		}
	}

    divsCnt[1] = 1;
    for (int s = 2; s <= MAX_S; ++s) {
        int n = s, product = 1;
        
		while (n != 1) {
            int p = spf[n], cnt = 0;
            while (spf[n] == p) {
                cnt++;
                n /= p;
            }

            product *= (2 * cnt + 1);
        }

        divsCnt[s] = product;
    }

    for (int i = 1; i <= MAX_S; ++i) pref[i] = pref[i-1] + divsCnt[i];

    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;

        long long sqMn = sqrtl(l - 1);
        sqMn = sqMn + 1;
        long long sqMx = sqrtl(r);

        if (sqMn > sqMx) {
            cout << 0 << '\n';
            continue;
        }

        long long total = pref[sqMx] - (sqMn > 0 ? pref[sqMn - 1] : 0);
        long long ans = total - (sqMx - sqMn + 1);
        cout << ans << '\n';
    }

    return 0;
}

/*
6
1 1
1 2
1 4
2 8
3 9
5 37
*/
