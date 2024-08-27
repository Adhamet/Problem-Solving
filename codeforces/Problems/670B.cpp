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

ll result(int n, int k) 
{
	int c = 0;
	for(int i = 1; i <= n; i++) {
		c+=i;
		if(k-i > 0) k-=i;
		else return k;
	}
}

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);

	int n,k;
	cin >> n >> k;
	vector<int> vec(n);
	for(int i = 0; i < n; i++) cin >> vec[i];
	cout << vec[result(n,k)-1];

    return 0;
}