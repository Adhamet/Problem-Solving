#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;	std::cin >> s;
	auto lucky = [&](std::string t) {
		int a = (t[0]-'0') + (t[1]-'0') + (t[2]-'0');
		int b = (t[3]-'0') + (t[4]-'0') + (t[5]-'0');
		return a == b;
	};

	int n = std::stoi(s);
	for (int d : {-1, 1}) {
		int x = n + d;
		if (x < 0 || x > 999999) continue;
		std::string t = std::to_string(x);
		while ((int)t.size() < 6) t = '0' + t;
		if (lucky(t)) return std::cout << "Yes", 0;
	}

	return std::cout << "No", 0;
}

