#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int n, even = 0, odd = 0;  cin >> n;
    for(int i = 0; i < n; i++) {
        int cow;    cin >> cow;
        if(cow%2==0) even++;
        else odd++;
    }

    while(odd>even) even+=1, odd-=1;
    if(even>odd-1) even = odd + 1;
    cout << odd + even << el;

    return 0;
}
