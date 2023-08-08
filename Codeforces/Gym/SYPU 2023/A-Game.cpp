#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

void solve() 
{
    int n,p,q,Sa=0,Sb=0;
    cin >> n >> p >> q;
    vector<int> vec(n);
    for(int i = 0; i<n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    int pt1=0,pt2=n-1; // missing test case?????
    while(q && vec[pt1] <= 0) Sb +=vec[pt1], pt1++, q--;
    while(p && vec[pt2] > 0) Sa += vec[pt2], pt2--, p--;
    if (!p && q && vec[pt1]) 
    cout << Sa - Sb << el;
}

int main() 
{/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */

    int t=1;
    cin >> t;
    while(t--) 
        solve();

	return 0;
}
