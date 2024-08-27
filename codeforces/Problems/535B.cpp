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

int n;
long long saddas(long long val, int idx) {
	// base case
	if(val > n) return -1;
	else if(val == n) return idx;
	
	return max(
		saddas(val*10+4, idx*2+1),
		saddas(val*10+7, idx*2+2)
	);
}

int main()
{
	adhamet;

	cin >> n;
	cout << saddas(0,0);

	return 0;
}
