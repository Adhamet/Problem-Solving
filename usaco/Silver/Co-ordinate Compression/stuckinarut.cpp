#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

struct Cow {
	pi coordinates;
	int id;

	Cow(pi p, int i): coordinates(p), id(i) {}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<Cow> cowsNorth, cowsEast;
	for (int i = 0; i < n; i++) {
		char direction;
		int x, y;
		cin >> direction >> x >> y;
		if (direction == 'N') cowsNorth.push_back(Cow({x, y}, i));
		else cowsEast.push_back(Cow({x, y}, i));
	}

	sort(cowsNorth.begin(), cowsNorth.end(), [](const Cow &a, const Cow &b) {
			if (a.coordinates.first == b.coordinates.first)
				return a.coordinates.second < b.coordinates.second;
			return a.coordinates.first < b.coordinates.first;
	});
	sort(cowsEast.begin(), cowsEast.end(), [](const Cow &a, const Cow &b) {
			if (a.coordinates.second == b.coordinates.second)
				return a.coordinates.first < b.coordinates.first;
			return a.coordinates.second < b.coordinates.second;
	});

	vector<bool> stopped(n, false);
	vector<int> blame(n, 0);

	for (const auto &eastCow : cowsEast) {
		for (const auto &northCow : cowsNorth) {
			if (!stopped[eastCow.id] && !stopped[northCow.id] &&
				eastCow.coordinates.second >= northCow.coordinates.second &&
				eastCow.coordinates.first <= northCow.coordinates.first) {

				int xDistance = northCow.coordinates.first - eastCow.coordinates.first;
				int yDistance = eastCow.coordinates.second - northCow.coordinates.second;

				if (yDistance < xDistance) {
					stopped[eastCow.id] = true;
					blame[northCow.id] += 1 + blame[eastCow.id];
				} else if (yDistance > xDistance) {
					stopped[northCow.id] = true;
					blame[eastCow.id] += 1 + blame[northCow.id];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) cout << blame[i] << '\n';

	return 0;
}
