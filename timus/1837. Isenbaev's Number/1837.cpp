#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	std::map<std::string, std::vector<std::string>> g;
	std::set<std::string> names;
	for (int i = 0; i < n; ++i) {
		std::string a, b, c;
		std::cin >> a >> b >> c;
		std::vector<std::string> t = {a, b, c};
		for (auto &x: t) names.insert(x);
		for (auto &x: t) for (auto &y: t) if (x != y) g[x].push_back(y);
	}

	std::map<std::string, int> dist;
	std::queue<std::string> q;
	if (names.count("Isenbaev")) {
		dist["Isenbaev"] = 0;
		q.push("Isenbaev");
		while (!q.empty()) {
			std::string u = q.front();
			q.pop();
			for (auto &v: g[u]) if (!dist.count(v)) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	for (auto &name: names) {
		std::cout << name << ' ';
		if (dist.count(name)) std::cout << dist[name] << '\n';
		else std::cout << "undefined" << '\n';
	}
	return 0;
}
