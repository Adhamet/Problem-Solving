#include <bits/stdc++.h>
using namespace std;

bool is_valid(const string& num) {
    int odd_sum = 0, even_sum = 0;
    bool turn = true;  // Track whether it's an even or odd position.
    for (char d : num) {
        int digit = d - '0';
        if (turn) even_sum += digit;
        else odd_sum += digit;
        turn = !turn;
    }
    // Check divisibility by 11 and 3
    return ((odd_sum - even_sum) % 11 == 0) && ((odd_sum + even_sum) % 3 == 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Handle special cases directly.
        if (n == 1 || n == 3) {
            cout << -1 << '\n';
            continue;
        }
        if (n == 2) {
            cout << 66 << '\n';
            continue;
        }

        // Generate the initial number: n-1 '3's and a '6'
        string num(n - 1, '3');
        num.push_back('6');

        // Try to find the smallest valid number.
        bool found = false;
        do {
            if (is_valid(num)) {
                cout << num << '\n';
                found = true;
                break;
            }
        } while (next_permutation(num.begin(), num.end()));

        if (!found) cout << -1 << '\n';
    }

    return 0;
}

