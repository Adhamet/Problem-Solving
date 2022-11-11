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

const ll N = 1e15;

void solve()
{
    int n,h,x,total=0;
    cin >> n >> h;
    while(n--) {
        cin >> x;
        if(x > h)
            total+=2;
        else total+=1;
    }
    cout << total;
}

int main()
{
    adhamet

    solve();
    return 0;
}