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
    int lamik,bob,i=0;
    cin >> lamik >> bob;

    while(lamik<=bob) {
        bob*=2;
        lamik*=3;
        i++;
    }
    cout << i;
}

int main()
{
    adhamet

    solve();
    return 0;
}