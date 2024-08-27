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

struct co_ordinates {
	int x,y;
};

int main()
{
    adhamet;
    setIO("balancing");

    int n,b;	cin >> n >> b;

    vector<int> x_cors{0}, y_cors{0};
    vector<co_ordinates> pts;

	for(int i = 0; i < n; i++) {
		co_ordinates pt;	cin >> pt.x >> pt.y;
		x_cors.push_back(pt.x-1);
		y_cors.push_back(pt.y-1);
		pts.push_back(pt);
	}

	int smallest_max = INT_MAX;
	for(const auto& x: x_cors) {
		for(const auto& y: y_cors) {
			int bl=0,tl=0,br=0,tr=0;
			for(auto &cow: pts) {
				if(cow.x < x && cow.y < y)
					bl++;
				else if(cow.x < x && cow.y > y)
					tl++;
				else if(cow.x > x && cow.y < y)
					br++;
				else if(cow.x > x && cow.y > y)
					tr++;
			}

			int max_region = max({bl,tl,br,tr});
			smallest_max = min(smallest_max, max_region);
		}
	}
	cout << smallest_max;

    return 0;
}