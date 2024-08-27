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

int main()
{
    adhamet;

    int n;	cin >> n;

    int x[n];
    for(int i = 0; i < n; i++) cin >> x[i];
    int y[n];
	for(int i = 0; i < n; i++) cin >> y[i];

	int mx=0, dist;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			dist = pow(x[i]-x[j],2)+pow(y[i]-y[j],2);
			mx = max(mx,dist);
		}
	}
	cout << mx;
	
    return 0;
}