#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    int mxA = *std::max_element(a.begin(), a.end());
    std::vector<int> freq(mxA + 1, 0);
    for (int x: a) freq[x]++;

    std::vector<int> digits(mxA + 10, 0);
    for (int i = 0; i <= mxA; i++) digits[i] = freq[i];

    for (int i = 0; i < (int)digits.size(); i++) {
        if (digits[i] >= 10) {
            if (i + 1 == (int)digits.size()) digits.push_back(0);
            digits[i + 1] += digits[i] / 10;
            digits[i] %= 10;
        }
    }

    int temp = n;
    for (int i = 0; temp > 0; i++) {
        if (i >= (int)digits.size()) digits.push_back(0);
        int d = temp % 10;
        if (digits[i] < d) {
            int j = i + 1;
            while (j < (int)digits.size() && digits[j] == 0) {
                digits[j] = 9;
                j++;
            }
            if (j < (int)digits.size()) digits[j]--;
            digits[i] += 10;
        }
        digits[i] -= d;
        temp /= 10;
    }

    while (digits.size() > 1 && digits.back() == 0) digits.pop_back();

    std::vector<int> ans;
    int rem = 0;
    for (int i = (int)digits.size() - 1; i >= 0; i--) {
        int cur = rem * 10 + digits[i];
        ans.push_back(cur / 9);
        rem = cur % 9;
    }

    while (ans.size() > 1 && ans[0] == 0)
        ans.erase(ans.begin());

    for (int d: ans) std::cout << d;
    return std::cout << '\n', 0;
}

