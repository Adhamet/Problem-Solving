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
    	string s;	cin >> s;
    	if(n==1 || n==2) {
    		cout << 0 << el;
    		continue;
    	}
    	int to_delete=0;
    	for(int i = 0; i < n-2; i++) {
    		if(n-i >= 5) {
    			if(s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p' && s[i+3] == 'i' && s[i+4] == 'e') {
    				to_delete++;
    				i+=4;
    				continue;
    			}
    		}
    		if(s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p') {
    			to_delete++;
    		}
    		if(s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e') {
    			to_delete++;
    		}
    	}
    	cout << to_delete << el;
    }
	
    return 0;
}