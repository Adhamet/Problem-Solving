#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    int t;	cin >> t;

    while(t--) {
    	int n;	cin >> n;
    	vector<int> nums(n);

    	for(int i = 0; i < n; i++) nums[i] = n - i;

    	ll sum = 0, num = 1;
    	for(int i = 1; i <= n; i++) {
    		sum += num * i;
    		num += 2;
    	}
    	cout << sum << " " << 2*n << el;

    	for(int i = 1; i <= n; i++) {
    		// rows
    		cout << 1 << " " << i << " ";
    		for(int x: nums) cout << x << " ";
    		cout << el;

    		// cols
    		cout << 2 << " " << i << " ";
    		for(int x: nums) cout << x << " ";
    		cout << el; 
    	}
    }
		
    return 0;
}