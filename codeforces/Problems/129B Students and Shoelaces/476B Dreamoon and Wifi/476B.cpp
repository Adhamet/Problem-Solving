#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long

double fact(double n) {
    double result = 1;
    for (double i = 2; i <= n; ++i)
        result *= i;
    return result;
}

double calc(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact(n) / (fact(r) * fact(n - r));
}

int main() {
    ios_base::sync_with_stdio(0), std::cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int splus = 0, sminus = 0, tplus = 0, tminus = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') splus += 1;
        else if (s[i] == '-') sminus += 1;
    }

    int qmarks = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '+') tplus += 1;
        else if (t[i] == '-') tminus += 1;
        else qmarks += 1;
    }

    int target = (splus - sminus) - (tplus - tminus);
    cout << fixed << setprecision(12);
    if (abs(target) > qmarks || (qmarks + target) % 2 != 0) {
        cout << fixed << setprecision(12) << 0.0 << el;
        return 0;
    }

    int r = (qmarks + target) / 2;
    double totPoss = pow(2, qmarks);
    double whatImLookingFor = calc(qmarks, r);
    cout << (whatImLookingFor / totPoss) << el;
    return 0;
}
