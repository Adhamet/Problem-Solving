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
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int dist = abs(a-b);
    if (dist > ( abs(a-c) + abs(b-d) ))
        dist = abs(a-c) + abs(b-d);
    if (dist > ( abs(a-d) + abs(b-c)))
        dist = abs(a-d) + abs(b-c);
    cout << dist << endl;

    return 0;
}
