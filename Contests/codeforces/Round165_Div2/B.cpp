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
    	string s;	cin >> s;
    	int n = s.size();

    	int l = 1;
    	while(l<n) {
    		int r = l+1;
    		while(l<=r && s[r] == '1') {
    			r++;
    		}
    	}
    }
	
    return 0;
}