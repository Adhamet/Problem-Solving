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

// void setIO(string name = "") {
// 	if (name.size()) {
// 		freopen((name+".in").c_str(), "r", stdin);
// 		freopen((name+".out").c_str(), "w", stdout);	
// 	}
// }



int main()
{
    adhamet;
    // setIO("blist");

    int t;	cin >> t;
    while(t--) {
    	int n,m;	cin >> n >> m;
    	vector<int> vec(n);
    	ull product = 1;
    	for(int i = 0; i < n; i++) {
    		cin >> vec[i];
    		product *= vec[i];
    	}

    	string s;
    	cin >> s;
    	int p1=0,p2=n-1;
    	for(int i = 0; i < s.size(); i++) {
    		if(s[i]=='L') {
    			cout << product%m << " ";
    			product /= vec[p1++];
    		} else {
    			cout << product%m << " ";
    			product /= vec[p2--];
    		}
    	}
    	cout << el;
    }
	
    return 0;
}