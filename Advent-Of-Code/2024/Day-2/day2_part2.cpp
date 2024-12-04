#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

bool isSafe(vector<int>& a) {
    int n = a.size();
    bool inc = (a[0] < a[1]);
    for (int i = 0; i < n - 1; i++) {
        int diff = abs(a[i] - a[i + 1]);
        if (inc) {
            if (!(a[i] < a[i + 1]) || !(diff >= 1 && diff <= 3)) {
				return false;
			}
        } else {
            if (!(a[i] > a[i + 1]) || !(diff >= 1 && diff <= 3)) {
				return false;
			}
        }
    }

    return true;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen("input.txt", "r", stdin);

	int safes = 0;
	string s;
	while (getline(cin, s)) {
		istringstream iss(s);

		int num;
		vector<int> a;
		while (iss >> num) a.push_back(num);

		if (isSafe(a)) {
			safes += 1;
			continue;
		}

		bool fixed = false;
		for (int i = 0; i < a.size(); i++) {
			vector<int> tmp = a;
			tmp.erase(tmp.begin() + i);
			if (isSafe(tmp)) {
				safes += 1, fixed = true;
				break;
			}
		}
	}

	cout << safes << el;
	return 0;
}
