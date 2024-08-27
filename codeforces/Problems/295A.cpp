#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
 
void solve()
{
    int n,m,k;

    cin >> n >> m >> k;

    vector<int> arr(n + 1);
    pair<intPair, int> op[m + 2]; 
    // first.first == l, first.second == r, second = value(d).

    // Taking input:
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= m; i++) {
        cin >> op[i].first.first >> op[i].first.second;
        cin >> op[i].second;
    }

    // N(o@t): Calculating number of operations at various instances.
    int l,r;
    vector<int> op_count(m + 2, 0);
    while (k--)
    {
        cin >> l >> r;
        op_count[l] += 1;
        op_count[r + 1] -= 1;
    }
    for (int i = 1; i <= m; i++)
        op_count[i] += op_count[i - 1];
    
    // Using N(o&t) to calculate values at various instances.
    vector<int> vc(n + 2, 0);
    for (int i = 1; i <= m; i++) if(op_count[i])
    {
        int l = op[i].first.first, r = op[i].first.second;
        vc[l] += (op_count[i] * op[i].second);
        vc[r + 1] -= (op_count[i] * op[i].second);
    }
    for (int i = 1; i <= n; i++) {
        vc[i] += vc[i - 1];
        arr[i] += vc[i];
    }

    // Printing arrays' elements:
    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
}
 
int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    solve();
 
	return 0;
}