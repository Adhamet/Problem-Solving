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
	int n,m,c,t;
	cin >> n >> m;

	int arr[n+2];
	arr[0]=1;
	for(int i = 1; i <= n; i++) {
		cin >> c >> t;
		arr[i] = arr[i-1] + c * t;
	}

	int min;
	int l,r,mid,ans;
	while(m--) {
		l = 1, r = n;
		cin >> min;

		while(l != r) {
			mid = (l+r)/2;

			if (arr[mid] < min) l = mid + 1;
			else if (arr[mid] > min) r = mid;
			else l = mid + 1;
		}
		cout << l;
	}
	
    return 0;
}