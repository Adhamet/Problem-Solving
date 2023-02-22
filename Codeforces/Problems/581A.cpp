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
    int red,blue,min,max;
    cin >> red >> blue;

    min = red < blue? red : blue;
    max = red > blue? red : blue;

    cout << min << " ";

    max -= min;

    if(max > 1) { cout << max/2; }
    else { cout << 0; }
}

int main()
{
    //adhamet

    solve();

    return 0;
}