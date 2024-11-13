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
    int n, p, q, temp;
    cin >> n;
    map<int,int> numbers;
    for(int i = 1; i <= n; i++) numbers[i] = 0;
    cin >> p;
    for(int i = 1; i <= p; i++)
    {
        cin >> temp;
        numbers[temp]++;
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        cin >> temp;
        numbers[temp]++;
    }
    for(auto number : numbers)
        if(number.second == 0) {
            cout << "Oh, my keyboard!";
            return;
        }
    cout << "I become the guy.";
}
 
int main()
{
    adhamet;
 
    solve();
    return 0;
}
