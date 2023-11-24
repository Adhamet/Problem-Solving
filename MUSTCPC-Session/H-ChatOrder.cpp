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
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	int n;	cin >> n;
	string input[n];
	map<string, bool> seen;

	for(int i = 0; i < n; i++) cin >> input[i];

	for(int i = n-1; i >= 0; i--) if(seen[input[i]] == false) {
		cout << input[i] << el;
		seen[input[i]] = true;
	}
	
    return 0;
}