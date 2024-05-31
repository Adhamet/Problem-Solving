#include <bits/stdc++.h>
using namespace std;

int main() {       
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
	    int n;	cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++) cin >> arr[i];

	    int ans = 0;
	    for (int i = 0; i < n - 2; ++i) {
		    for (int j = i + 1; j < n - 2; ++j) {
			    bool f = arr[i]!= arr[j];
			    bool s = arr[i + 1] == arr[j + 1];
			    bool t = arr[i + 2] == arr[j + 2];

			    if ((f && s && t) || (!f && !s && t) || (!f && s && !t))
				    ++ans;
		    }
	    }	    
	    cout << ans << '\n';
    }

    return 0;
}

