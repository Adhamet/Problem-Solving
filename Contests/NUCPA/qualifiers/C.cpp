#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
    int32_t n;
    scanf("%d", &n);
    
    vector<int32_t> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int32_t tot = a[0];
    for (int i = 1; i < n; ++i) tot = __gcd(tot, a[i]);

    if (tot != 1) {
        printf("-1");
    } else printf("%d", n);

	return 0;
}
