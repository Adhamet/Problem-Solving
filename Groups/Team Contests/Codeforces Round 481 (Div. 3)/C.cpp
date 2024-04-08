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

    int n,m;	cin >> n >> m;
    ull dorms[n];
    vector<ull> rooms(n+1);
    for(int i = 0; i < n; i++)
    	cin >> dorms[i];
    rooms[0] = 0;
    for(int i = 1; i <= n; i++)
    	rooms[i] = rooms[i-1] + dorms[i-1];
	
	for(int i = 0; i < m; i++) {
		ull a;	cin >> a;

		int l=0,r=n-1;
		int idxDorm;
		while(l<=r) {
			int mid = l + (r-l) / 2;

			if(rooms[mid]<a) l=mid+1,idxDorm=mid;
			else if(rooms[mid]>=a) r=mid-1;
		}
		cout << idxDorm+1 << " " << a - rooms[idxDorm] << el;
	}

    return 0;
}