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
int n,tim,GEN = 240;
bool can(int slvd) {
	int total = 0;
	for(int i = 1; i <= slvd; i++)
		total += 5*i;
	if (GEN - total >= tim) return true;
	else return false;
}

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	cin >> n >> tim;

	int l=0,r=n,mid,ans=0;
	while(l <= r) {
		mid = (l+r)/2;

		if(can(mid)) { ans = mid; l = mid + 1;}
		else r = mid - 1;
	}
	cout << ans;

    return 0;
}