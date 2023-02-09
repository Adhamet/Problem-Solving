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
    int n, d=0, temp;
    ll iCr;
    char op;
    cin >> n >> iCr;
    
    for(int i = 0; i < n; i++)
    {
        cin >> op >> temp;
        if(op == '+')
            iCr += temp;
        else{
            if(temp > iCr) d++;
            else iCr -= temp;
        }
    }

    cout << iCr << " " << d << el;
}

int main()
{
    adhamet
    
    solve();
    return 0;
}