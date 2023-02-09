#include <bits/stdc++.h>
using namespace std;
#define adhamet ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve()
{
    int n;
    cin >> n;
    pair<int,int> pr[n];
    for(int i = 0; i < n; i++) cin >> pr[i].first >> pr[i].second;
    sort(pr, pr+n);
    for(int i = 0; i < n-1; i++) if(pr[i].first < pr[i+1].first && pr[i].second > pr[i+1].second)
    {
        return cout << "Happy Alex" << endl, 0;
    }
    return cout << "Poor Alex" << endl, 0;
}

int main()
{
    adhamet;

    solve();

    return 0;
}