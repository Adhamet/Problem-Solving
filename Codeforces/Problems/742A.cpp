#include <bits/stdc++.h>
using namespace std;
#define adhamet ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve()
{
    long long n;
    cin >> n;
    if(n==0) cout << '1';
    else if(n%4==0) cout << '6';
    else if(n%4==1) cout << '8';
    else if(n%4==2) cout << '4';
    else if(n%4==3) cout << '2';
}

int main()
{
    adhamet;

    solve();

    return 0;
}