#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'
 
void solve()
{
    int n, lr, x;
    cin >> n >> lr;
    deque<int> dq;

    for(int i = 0; i < n; i++) {
        cin >> x;
        dq.push_back(x);
    }
    for(int i = 0; i < lr; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
    }
    for(auto itm: dq) cout << itm << " ";
}

int main()
{
    adhamet
 
    solve();
 
    return 0;
}