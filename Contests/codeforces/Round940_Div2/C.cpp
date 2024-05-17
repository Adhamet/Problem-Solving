#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define MOD 1000000007
int n;
vector<bool> col,row;
int cnt = 0;

// + + + +
// + + + +
// + + - -
// + + - -
void sol(int r) {
	if(r == n) {
		cnt = (cnt + 1) % MOD;
		return;
	}

	for(int c = 0; c < n; c++) {
		if(col[c]) continue;

		col[c] = true;
        if(r != c) col[r] = true;
        sol(r+1);
        col[c] = false;
        if(r != c) col[r] = false;
	}
}

int main()
{
	adhamet;
    
	int t;	cin >> t;
	while(t--) {
		int n,k;	cin >> n >> k;
		col.assign(n,0);

		for(int i = 0; i < k; i++) {
			int x,y;	cin >> x >> y;
			col[y-1] = true;
			if(x!=y) col[x-1] = true;
		}

		cnt = 0;
		sol(0);

		cout << cnt;
	}

    return 0;
}