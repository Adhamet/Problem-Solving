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

    int n;	cin >> n;
    int arr[n];
    vector<int> ans;
    map<int,int> freq;
    for(int i = 0; i < n; i++) {
    	cin >> arr[i];
    }

    for(int i = n-1; i>=0; i--) {
    	if(!freq[arr[i]]) {
    		ans.push_back(arr[i]);
    	}

    	freq[arr[i]]++;
    }

    reverse(ans.begin(),ans.end());
    cout << ans.size() << el;
    for(auto a: ans) cout << a << " ";

    return 0;
}