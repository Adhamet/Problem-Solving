#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int k, a, b, n;
string s;
vector<vector<int>> memo;
vector<int> choice;

bool recurse(int i, int lines) {
    if (i == n) return lines == 0;
    if (lines == 0) return false;
    if (memo[i][lines] != -1) return memo[i][lines];

    for (int chars = a; chars <= b; chars++) {
        if (i + chars <= n && recurse(i + chars, lines - 1)) {
			choice[i] = chars;
			return memo[i][lines] = 1;
        }
    }

    return memo[i][lines] = 0;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> k >> a >> b >> s;
    n = s.size();

	choice.assign(n, -1);
    memo.assign(n + 1, vector<int>(k + 1, -1));

	if (!recurse(0, k)) {
        cout << "No solution" << el;
        return 0;
    }

    int i = 0;
    while (i < n) {
        cout << s.substr(i, choice[i]) << el;
        i += choice[i];
    }

    return 0;
}

