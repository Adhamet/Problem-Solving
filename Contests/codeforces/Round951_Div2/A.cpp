#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
	
int main() {
	ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    
    int t;  cin >> t;
    while(t--) {
        int n;  cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];

        set<int> vals;
        for(int i = 0; i < n-1; i++) {
            vals.insert(max(arr[i],arr[i+1]));
        }

        int mn = INT_MAX;
        for(auto val: vals) {
            mn = min(mn, val);
        }

        cout << mn - 1 << el;
    }
    
    return 0;
}

