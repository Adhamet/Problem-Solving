#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el endl

int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    int n,x;
    cin >> n;

    int cnt=1;
    vector<int> vec(n),ans;
    for (auto &i: vec)
        cin >> i;
    for (int i = 1; i < n; i++) if (vec[i] == 1)
        ans.push_back(vec[i-1]);
    ans.push_back(vec.back());
    cout << ans.size() << el;
    for (auto &i: ans)
        cout << i << " ";

	return 0;
}
