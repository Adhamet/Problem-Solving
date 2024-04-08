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
    	int n,m,k;	cin >> n >> m >> k;
    	int left[n], right[n];
    	for(int i = 0; i < n; i++) cin >> left[i];
    	for(int i = 0; i < m; i++) cin >> right[i];
    	sort(left, left+n);
    	sort(right,right+m);

    	int ways=0;
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			if(left[i] + right[j] <= k) {
    				ways++;
    			} else {
    				break;
    			}
    		}
    	}
    	cout << ways << el;
    }
	
    return 0;
}