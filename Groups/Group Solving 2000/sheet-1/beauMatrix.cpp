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
    int x;
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++) {
            cin >> x;
            if(x == 1){
                cout << abs(i-3) + abs(j-3) << el;
                break;
            }       
        }
}

int main()
{
    adhamet

    solve();
    return 0;
}