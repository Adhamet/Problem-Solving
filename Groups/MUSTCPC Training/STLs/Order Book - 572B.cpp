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
    map<int, int> buys, sells;
    int nOrd,s,p,vol;
    char op;
    cin >> nOrd >> s;
    while(nOrd--)
    {
        cin >> op;
        if (op == 'B')
        {
            cin >> p >> vol;
            buys[p] += vol;
        }
        else if (op == 'S')
        {
            cin >> p >> vol;
            sells[p] += vol;
        }
    }

    int temp = s;
    stack<intPair> sellsF;
    for(auto itm: sells)
    {
        if(s > 0) { sellsF.push({itm.first, itm.second}); }
        else break;
        s--;
    }

    s = temp;
    while(!sellsF.empty())
    {
        cout << 'S' << " " << sellsF.top().first << " " << sellsF.top().second << endl;
        sellsF.pop();
    }
    for(auto itr = buys.rbegin(); itr != buys.rend(); itr++) 
        if(s > 0) { cout << 'B' << " " << itr->first << " " << itr->second << endl; s--; }
}
 
int main()
{
    adhamet
 
    solve();
 
    return 0;
}