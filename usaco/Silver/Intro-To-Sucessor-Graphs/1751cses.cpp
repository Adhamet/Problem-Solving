#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

const int MAXN = 2e5 + 5;
queue<int> path;
bool vis[MAXN]{};
int dest[MAXN], pathLen[MAXN], steps = 0;

void dfs(int planet) {
	path.push(planet);
	if (vis[planet]) {
		steps += pathLen[planet];
		return;
	}

	steps += 1;
	vis[planet] = true;
	dfs(dest[planet]);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dest[i];
		dest[i] -= 1;
	}

	for (int i = 0; i < n; i++) if (!vis[i]) {
		steps = 0;
		dfs(i);

		int decrement = 1;
		while (!path.empty()) {
			if (path.front() == path.back()) decrement = 0;
			pathLen[path.front()] = steps;
			steps -= decrement;
			path.pop();
		}
	}

	for (int i = 0; i < n; i++) cout << pathLen[i] << " ";
	cout << el;
	return 0;
}
