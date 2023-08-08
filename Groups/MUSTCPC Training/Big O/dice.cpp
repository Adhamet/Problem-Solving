// Dice
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

int main()
{
    adhamet

    int n,z,x,y;
    cin >> n >> z;
    for ( int i = 0 ; i < n; i++ )
    {
        cin >> x >> y;
        if ( x==z || x == 7 - z || y == z || y == 7 - z )
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
