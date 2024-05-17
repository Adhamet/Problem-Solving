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
		adhamet
	    int t;
	    cin >> t;
	    while (t--) {
	        int n;
	        cin >> n;
	        vector<int> a(n), b(n);
	        for (int i = 0; i < n; ++i) cin >> a[i];
	        for (int i = 0; i < n; ++i) cin >> b[i];

	        sort(a.begin(), a.end());

	        int cnt = 0;
	        for (int i = 0; i < n; ++i) {
	            if (a[i] > b[i]) {
	                a.insert(a.begin() + i, b[i]);
	                a.pop_back();
	                cnt++;
	            }
	        }

	        cout << cnt << endl;
	    }
		
	    return 0;
	}