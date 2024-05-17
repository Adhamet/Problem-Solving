#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
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
    // setIO("blist");

	int t;	cin >> t;
	while(t--) {
		int n;	cin >> n;
		vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

		bool acc = false;
		for(int i = 1; i <= n; i++) {
			if(arr[arr[i]] == i) {
				acc = true;
				break;
			}
		}

		if(acc) cout << 2 << el;
		else cout << 3 << el;
	}
	
    return 0;
}