#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    char a[205], b[205];
    int ans[205];

    while (n--) {
        for (int i = 0; i < 205; i++) a[i] = '0', b[i] = '0', ans[i] = 0;
        cin >> a >> b;
        int len1 = strlen(a), len2 = strlen(b);
        while (len1 > 0 && a[len1 - 1] == '0') len1--;
        while (len2 > 0 && b[len2 - 1] == '0') len2--;
        for (int i = 0; i < len1; i++) ans[i] = a[i] - '0';
        for (int i = 0; i < len2; i++) ans[i] += (b[i] - '0');
        
        int maxLength = max(len1, len2);
        for (int i = 0; i < maxLength; i++) {
            if (ans[i] >= 10) {
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
                if (i == maxLength - 1) maxLength++;
            }
        }

        int startIndex = 0;
        while (startIndex < maxLength && ans[startIndex] == 0) startIndex++;
        for (int i = startIndex; i < maxLength; i++) cout << ans[i];
        cout << el;
    }

	return 0;
}
