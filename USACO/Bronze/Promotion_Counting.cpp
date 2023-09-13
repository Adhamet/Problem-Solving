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
    adhamet;
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int bronzeBf, bronzeAf, silverBf, silverAf;
    cin >> bronzeBf >> bronzeAf >> silverBf >> silverAf;

    int goldBf, goldAf, platBf, platAf;
    cin >> goldBf >> goldAf >> platBf >> platAf;

    int gTOp = platAf - platBf;
    int sTOg = goldAf - goldBf + gTOp;
    int bTOs = silverAf - silverBf + sTOg;

    cout << bTOs << el << sTOg << el << gTOp;

    return 0;
}
