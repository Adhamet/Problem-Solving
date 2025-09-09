#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;   cin >> n >> k;
    vector<long long> w(10);
    for (int i = 0; i < 10; ++i) {
        cin >> w[i];
    }

    vector<long long> sms;
    for (int i = 0; i < n; ++i) {
        long long cursm = 0;
        for (int j = 0; j < 10; ++j) {
            long long x;    cin >> x;
            cursm += (x * w[j]);
        }
        sms.push_back(cursm);
    }

    sort(sms.begin(), sms.end(), greater<long long>());
    long long ans = 0;
    for (int i = 0; i < k; ++i)
        ans += sms[i];
    cout << ans;
}
