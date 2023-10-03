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
	
	int n,k;
	cin >> n >> k;
	int arr[n];
	ll walks = 0;
	
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < n-1; i++) if(arr[i] + arr[i+1] < k) {
		int change = k - (arr[i] + arr[i+1]);
		walks+= change;
		arr[i+1] += change;
	}
 
	cout << walks << el;
	for(int i = 0; i<n; i++) cout << arr[i] << " ";
 
    return 0;
}