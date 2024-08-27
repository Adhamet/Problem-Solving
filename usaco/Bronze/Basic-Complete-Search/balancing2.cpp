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

struct Cow {
	int x,y;
};

vector<int> pos_of_interest(vector<int>& pos) {
	int n = pos.size();
	sort(pos.begin(), pos.end());

	vector<int> distinct;

	vector<int> num_left;
	for(int i = 0; i < n; i++) {
		if(i==n-1 || pos[i]!=pos[i+1]) {
			distinct.push_back(pos[i]+1);
			num_left.push_back(i+1);
		}
	}

	vector<int> imp;
	for(int i = 0; i < distinct.size(); i++) {
		if(i+1 < distinct.size() && num_left[i+1] <= n/3) continue;
		if(i>0 && num_left[i-1] >= n - n / 3) continue;
		imp.push_back(distinct[i]);
	}

	return imp;
}

int main()
{
    adhamet;
    setIO("balancing");

    int n;	cin >> n;

    vector<Cow> cows(n);
    vector<int> x_cors{0}, y_cors{0};

	for(Cow &c: cows) {
		cin >> c.x >> c.y;
		x_cors.push_back(c.x);
		y_cors.push_back(c.y);
	}

	vector<int> to_check_x = pos_of_interest(x_cors);
	vector<int> to_check_y = pos_of_interest(y_cors);
	int smallest_max = INT_MAX;	
	for(const auto& x: to_check_x){
		for(const auto& y: to_check_y) {
			int bl=0,tl=0,br=0,tr=0;
			for(auto &cow: cows) {
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