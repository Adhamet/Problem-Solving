#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
	adhamet;

	int t;	cin >> t;
	while(t--) {
		int n;	cin >> n;
		ll arr[n];
		for(int i = 0; i < n; i++) cin >> arr[i]; // 1 2 3 4 5
		string s;	cin >> s; // 01000

		int xor0=0,xor1=0;
		for(int i = 0; i < n; i++) {
			if(s[i]=='0') xor0 ^= arr[i];
			else xor1 ^= arr[i];
		}

		int pref[n+1];
		pref[0] = 0;
		for(int i = 1; i <= n; i++)
			pref[i] = pref[i-1] ^ arr[i-1];
		
		int q;	cin >> q;
		while(q--) {
			int op;	cin >> op;
			if(op == 1) {
				int l,r;	cin >> l >> r;
				int mid = pref[l-1] ^ pref[r];
				xor0 ^= mid;
				xor1 ^= mid;
			}
			else {
				int bitval;	cin >> bitval;
				if(bitval == 0) cout << xor0 << " ";
				else cout << xor1 << " ";
			}
		}
		cout << el;
	}
	
    return 0;
}