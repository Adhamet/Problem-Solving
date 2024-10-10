// The answer would be to use (n - builtin_clz - builtin_tlz)
// if this is smaller than or equal to x then continue the bitmasking
// calculating the difficulty then afterwards make sure that 
// the difficulty is in the requested range.
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

// void setIO(string name = "") {
// 	if (name.size()) {
// 		freopen((name+".in").c_str(), "r", stdin);
// 		freopen((name+".out").c_str(), "w", stdout);	
// 	}
// }

int main()
{
    // setIO("blist");

    int n,l,r,x;	scanf("%d %d %d %d", &n,&l,&r,&x);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int cnt = 0;
    for(int mask = 0; mask < (1<<n); mask++) {
    	if (__builtin_popcount(mask) < 2) continue;
        int mn = INT_MAX, mx = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                mn = min(mn, arr[i]);
                mx = max(mx, arr[i]);
                sum += arr[i];
            }
        }
        if (sum >= l && sum <= r && mx - mn >= x) cnt++;
    }
    printf("%d", cnt);
	
    return 0;
}