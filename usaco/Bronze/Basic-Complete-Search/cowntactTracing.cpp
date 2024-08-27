#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
void setIO(string name = "");

struct Shake {
    int t, x, y;
    bool operator<(const Shake &tmp) { return t < tmp.t; }
};

int main()
{
    setIO("badmilk");
    adhamet;

    int n, t;
    string s;
    cin >> n >> t >> s;

    vector<Shake> shakes(t);
    vector<bool> cows_infected(n);
    unordered_set<int> possible_patient;
    int min_k = t, max_k = -1;

    auto is_consistent = [&](int patient_zero, int k) {
        vector<bool> tmp_infected(n);
        vector<int> num_shakes(n);
        tmp_infected[patient_zero] = true;
        for (Shake sh : shakes) {
            if (tmp_infected[sh.x]) { num_shakes[sh.x]++; }
            if (tmp_infected[sh.y]) { num_shakes[sh.y]++; }
            if (num_shakes[sh.x] <= k && tmp_infected[sh.x]) {
                tmp_infected[sh.y] = true;
            }
            if (num_shakes[sh.y] <= k && tmp_infected[sh.y]) {
                tmp_infected[sh.x] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (tmp_infected[i] != cows_infected[i]) { return false; }
        }
        return true;
    };

    for (int i = 0; i < n; i++) { cows_infected[i] = (s[i] == '1'); }

    for (Shake &sh : shakes) {
        cin >> sh.t >> sh.x >> sh.y;
        sh.t--, sh.x--, sh.y--;
    }
    sort(shakes.begin(), shakes.end());

    for (int patient_zero = 0; patient_zero < n; patient_zero++) {
        for (int k = 0; k <= t; k++) {
            if (is_consistent(patient_zero, k)) {
                possible_patient.insert(patient_zero);
                min_k = min(min_k, k);
                max_k = max(max_k, k);
            }
        }
    }

    cout << possible_patient.size() << " " << min_k << " "
         << (max_k == t ? "Infinity" : to_string(max_k)) << endl;

    return 0;
}
void setIO(string name) {
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
