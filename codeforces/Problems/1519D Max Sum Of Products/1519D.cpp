#include <bits/stdc++.h>
using namespace std;

#define el '\n';

int main()
{
    ios_base::sync_with_stdio(0);   cin.tie(0);     cout.tie(0);

    int n;  cin >> n;
    long long a[n], b[n];

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<long long> pref(n+1, 0);
    for(int i = 0; i < n; i++) pref[i+1] = pref[i] + a[i]*b[i];

    long long ans = pref[n];
    for(int i = 0; i < n; i++) {
        long long curr = a[i] * b[i];

        for(int l=i-1, r=i+1; l>=0 && r<n; l--, r++) {
            curr += a[l]*b[r];
            curr += a[r]*b[l];
            ans = max(ans, pref[l] + curr + (pref[n]-pref[r+1]));
        }

        curr = 0;
        for(int l=i, r=i+1; l>=0 && r<n; l--, r++) {
            curr += a[l]*b[r];
            curr += a[r]*b[l];
            ans = max(ans, pref[l] + curr + (pref[n]-pref[r+1]));
        }
    }
    cout << ans << el;

    return 0;
}
