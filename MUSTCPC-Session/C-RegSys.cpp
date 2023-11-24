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
	map<string,int> mp;
	string tmp;

	for(int i = 0; i < n; i++) {
		cin >> tmp;
		mp[tmp]++;
		if(mp[tmp] != 1)
			cout << tmp << mp[tmp]-1 << el;
		else cout << "OK" << el;
	}
	
    return 0;
}