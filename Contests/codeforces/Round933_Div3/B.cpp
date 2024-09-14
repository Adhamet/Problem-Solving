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

    int t;	cin >> t;
    while(t--) {
    	int n;	cin >> n;
    	int arr[n];
    	for(int i = 0; i < n; i++) cin >> arr[i];

    	bool acceptance = 1;
    	for(int i = 0; i < n-1; i++) {
    		if(abs(arr[i] - arr[i+1]) == 1) {
    			acceptance = 0;
    			continue;
    		}
    		if(arr[i] == arr[i+1]) {
    			acceptance = 0;
    			continue;
    		}
    	}
    	if(acceptance == 1) cout << "YES\n";
    	else cout << "NO\n";
    }
	
    return 0;
}