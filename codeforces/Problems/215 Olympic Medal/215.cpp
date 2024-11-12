#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main() {
    ios_base::sync_with_stdio(0), std::cin.tie(nullptr);

    double tmp;
    double n, mxRout = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> tmp, mxRout = max(mxRout, tmp);
    double m, mxP1 = 0;
    cin >> m;
    for (int i = 0; i < m; i++) cin >> tmp, mxP1 = max(mxP1, tmp);
    double k, mxP2 = 1e9;
    cin >> k;
    for (int i = 0; i < k; i++) cin >> tmp, mxP2 = min(mxP2, tmp);
    double A, B;
    cin >> A >> B;
    cout << fixed << setprecision(12) << mxRout * sqrt((B * mxP1) / (A * mxP2 + B * mxP1)) << el;
    return 0;
}
