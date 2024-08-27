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

// sum: 1,2,3...n..
ll sum(ll n)
{
    return (n * (n+1)) / 2;
}

// sum: s,s+1,s+2...e..
ll sum(ll s, ll e)
{
    if (s<=1)
        return sum(e);
    return sum(e) - sum(s-1);
}

ll minSplitters(ll k, ll n)
{
    ll st = 1, en = k;
    
    while(st < en)
    {
        ll md = (st + en)/2;
        ll s = sum(md, k);

        if(s == n)
            return k - md + 1;
        
        if(s > n)
            st = md+1;
        else
            en = md;
    }
    
    return k - st + 2;
}

int main()
{
    adhamet
    
    ll n,k;
    cin >> n >> k;

    if (n == 1)
        cout << 0 << el;
    else if(n <= k)
        cout << 1 << el;
    else
    {
        --k;
        --n;

        if(sum(k) < n)
            cout << -1 << el; 
        else
            cout << minSplitters(k,n) << el;
    }
    return 0;
}   