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
    	ll sum=-n;
    	for(int i = 1; i*i <= n; i++) {
    		if(n%i == 0) {
    			sum += i;
    			if(i!=n/i) {
    				sum+=n/i;
    			}
    		}
    	}
    	if(sum>n) cout << "abundant\n";
    	else if (sum<n) cout << "deficient\n";
    	else {
    		cout << "perfect\n";
    	}
    }
	
    return 0;
}