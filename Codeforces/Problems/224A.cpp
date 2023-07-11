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
    
    double ar1,ar2,ar3,a,b,c;
    cin >> ar1 >> ar2 >> ar3;
    a = sqrt(ar1 * ar2 / ar3);
    b = sqrt(ar3 * ar1 / ar2);
    c = sqrt(ar3 * ar2 / ar1);

    cout << 4 * (a+b+c);
    return 0;
}
