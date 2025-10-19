#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int c, r;	std::cin >> c >> r;
	int k;	std::cin >> k;
	std::set<std::pair<int,int>> diags;
	for (int i = 0; i < k; ++i) {
		int y, x;	std::cin >> y >> x;
		diags.insert({x, y});
	}


	using tdii = std::tuple<double,int,int>;
	std::priority_queue<tdii, std::vector<tdii>, std::greater<tdii>> pq;
	std::vector<std::vector<bool>> vis(r+2, std::vector<bool>(c+2, false));
	pq.push({0, 0, 0});

	auto inside = [&](int x, int y) { return x >= 0 && x <= r && y >= 0 && y <= c; };
	while (!pq.empty()) {
		double d = std::get<0>(pq.top());
		int x = std::get<1>(pq.top());
		int y = std::get<2>(pq.top());
		pq.pop();

		if (x == r && y == c) {
			std::cout << llround(d * 100);
			break;
		}

		if (inside(x+1, y+1) && !vis[x+1][y+1] && diags.count({x+1, y+1})) {
			pq.push({d+sqrt(2), x+1, y+1});
			vis[x+1][y+1] = true;
		}
		if (!vis[x+1][y] && inside(x+1,y)) {
			pq.push({d+1, x+1, y});
			vis[x+1][y] = true;
		}
		if (!vis[x][y+1] && inside(x,y+1)) {
			pq.push({d+1, x, y+1});
			vis[x][y+1] = true;
		}
	}
	
	return 0;
}
