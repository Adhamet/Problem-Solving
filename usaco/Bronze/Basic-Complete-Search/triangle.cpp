#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);	
	}
}

int main() {
	adhamet;
	setIO("triangles");

	int n;
	cin >> n;
	vector<int> x(n);  // x coordinates of all fence posts
	vector<int> y(n);  // y coordinates of all fence posts
	for (int i = 0; i < n; i++) { cin >> x[i] >> y[i]; }

	int max_area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (y[i] == y[j]) for (int k = 0; k < n; k++) {
				if (x[i] == x[k]) {
					int area = abs((x[j] - x[i]) * (y[k] - y[i]));
					max_area = max(max_area, area);
				}
			}
		}
	}

	cout << max_area << el;

	return 0;
}