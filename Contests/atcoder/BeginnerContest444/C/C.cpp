#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> freq;
    std::map<int,bool> exist;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        exist[a[i]] = 1;
        freq[a[i]] += 1;
    }

    std::sort(a.begin(), a.end());
    std::set<int> acq;
    acq.insert(*std::max_element(a.begin(), a.end()));
    for (int i = 0; i < n; i++) acq.insert(a[i] + a[0]);

    std::vector<int> ans;
    for (auto x: acq) {
        if (x < a.back()) continue;

        std::map<int,int> tmp = freq;
        bool acc = true;
        for (int i = 0; i < n; ++i) {
            if (tmp[a[i]] == 0) continue;
            if (a[i] == x) {
                tmp[a[i]]--;
                continue;
            }
            if (x - a[i] < 0 || !exist[x - a[i]] || tmp[x - a[i]] == 0) { 
                acc = false;
                break;
            }

            if (x - a[i] == a[i]) {
                if (tmp[a[i]] < 2) {
                    acc = false;
                    break;
                }
                tmp[a[i]] -= 2;
            } else {
                tmp[a[i]]--;
                tmp[x - a[i]]--;
            }
        }

        if (acc) ans.push_back(x);
    }

    std::sort(ans.begin(), ans.end());
    for (auto x: ans) std::cout << x << ' ';
    return 0;
}

