#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>

int main() {
    int n, x;
    cin >> n >> x;

    pair<ll, ll> a[n+5];
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    if (n==3 && (a[1].first + a[2].first + a[3].first)==x) {
        cout << a[1].second << " " << a[2].second << " " << a[3].second;
        return 0;
    } else {
        sort(a+1, a+n+1);
        for (int i = 1; i <= n-2; i++) {
            int j = i + 1, k = n;
            ll sum = a[i].first + a[j].first + a[k].first;
            while (j < k) {
                if (sum==x) {
                    cout << a[i].second << " " << a[j].second << " " << a[k].second;
                    return 0;
                } else if (sum < x) j += 1;
                else k -= 1;
                
				sum = a[i].first + a[j].first + a[k].first;
            }
        }
    }

    cout << "IMPOSSIBLE";
}
