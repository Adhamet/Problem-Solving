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
		freopen((name+".out").c_str(), "w", stdin);	
	}
}

int main()
{
    adhamet;
    setIO("cowsignal");

	int m,n,k;	cin >> m >> n >> k;	
	vector<string> signal(m);
	for(string &r: signal) { cin >> r; }

	for(int i = 0; i < m * k; i++) {
		for(int j = 0; j < n * k; j++) {
			cout << signal[i / k][j / k];
		}
		cout << el;
	}

    return 0;
}