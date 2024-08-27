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

int main()
{
    adhamet;
	setIO("speeding");

	const int DIST = 100;
	int n,m;	cin >> n >> m;
	vector<int> rules(DIST), bessie(DIST);

	int miles=0;
	for(int i = 0; i < n; i++) {
		int dist,speed;
		cin >> dist >> speed;
		for(int j = 0; j < dist; j++)
			rules[miles++] = speed;
	}

	miles=0;
	for(int i = 0; i < m; i++)
	{
		int dist,speed;
		cin >> dist >> speed;
		for(int j = 0; j < dist; j++)
			bessie[miles++] = speed;
	}

	int mx = 0;
	for(int i = 0; i < DIST; i++)
		if (bessie[i] > rules[i])
			mx = max(mx, bessie[i] - rules[i]);
	cout << mx << el;

    return 0;
}