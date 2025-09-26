#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	std::map<i64,i64> freq;
	std::set<i64> od, ev;
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		if (x & 1) od.insert(x);
		else ev.insert(x);
		freq[x] += 1;
	}

	i64 Alice = 0, Bob = 0;
	for (auto x: ev) {
		i64 val = freq[x] * x;
		Alice += val / 2;
		Bob += val / 2;
	}

	using od_t = std::tuple<i64,i64,i64>;
	std::vector<od_t> odScores;
	for (auto x: od) {
		i64 val1 = freq[x] * ((x + 1) / 2);
		i64 val2 = freq[x] * (x / 2);
		odScores.emplace_back(freq[x], val1, val2);
	}
	std::sort(odScores.begin(), odScores.end(), [](auto &a, auto &b) { 
			return std::get<0>(a) > std::get<0>(b);
		}
	);

	i64 path1 = 0, path2 = 0;
	bool alternate = true;
	for (int i = 0; i < (int)odScores.size(); ++i) {
		i64 val1 = std::get<1>(odScores[i]);
		i64 val2 = std::get<2>(odScores[i]);
		if (alternate) {
			path1 += val1;
			path2 += val2;
		} else {
			path1 += val2;
			path2 += val1;
		}
		alternate = !alternate;
	}

	Alice += std::max({path1, path2});
	Bob += std::min({path1, path2});
	std::cout << Alice << ' ' << Bob << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}

