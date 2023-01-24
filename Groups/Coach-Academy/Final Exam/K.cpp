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

const int N = 1e7+5;
vector<bool> isPrime(N, 1);
int a[N], seg[N], lazy[N], oL, oR, value;

void Sieve()
{
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2; i*i <= N; i++)
        if( isPrime[i] )
            for(ll j = i*i; j <= N; j+=i)
                isPrime[j] = false;
}

void check(int idx, int l, int r)
{
    if(lazy[idx] != 0)
    {
        if(lazy[idx] > 1e7)
            seg[idx] = 0;
        else seg[idx] = isPrime[lazy[idx]] * ( r - l + 1 );
        if( l != r )
        {
            lazy[idx*2] = lazy[idx];
            lazy[idx*2+1] = lazy[idx];
            lazy[idx] = 0;
        }
    }
}

void build(int idx, int l, int r)
{
    if (l == r)
    {
        if(a[l] > 1e7)
            seg[idx] = 0;
        else
            seg[idx] = isPrime[a[l]];
        lazy[idx] = a[l];
        return;
    }
    build(idx*2, l, (l+r) / 2);
    build(idx*2+1, (l+r) / 2 + 1, r);
    seg[idx] = seg[idx*2] + seg[idx*2 + 1];
}

void add(int idx, int l, int r)
{
    check(idx, l , r);
    if( l > oR || r < oL )
        return;
    else if ( l == r ) 
    {
        lazy[idx] += value;
        check(idx,l,r);
        return;
    }
    add(idx*2,l,(l+r)/2);
    add(idx*2+1, (l+r)/2+1, r);
    seg[idx] = seg[idx*2] + seg[idx*2 + 1];
}

void update(int idx, int l, int r)
{
    check(idx,l,r);
    if(l > oR || r < oL)
        return;
    if(l >= oL && r <= oR) {
        lazy[idx] = value;
        check(idx,l,r);
        return;
    }
    update(idx*2,l,(l+r)/2);
    update(idx*2+1, (l+r)/2+1, r);
    seg[idx] = seg[idx*2] + seg[idx*2 + 1];
}

int get(int idx, int l, int r)
{
    check(idx,l,r);
    if( l > oR || r < oL)
        return 0;
    else if (l >= oL && r <= oR)
        return seg[idx];
    int left = get(idx*2,l,(l+r)/2);
    int right = get(idx*2+1, (l+r)/2+1, r);
    return left+right;
}

void solve()
{
    int n,OPE;
    cin >> n >> OPE;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1,1,n);

    while(OPE--)
    {
        char type;
        cin >> type;
        if ( type == 'A' )
        {
            cin >> value >> oL;
            oR = oL;
            add(1,1,n);
        }
        else if ( type == 'R' )
        {
            cin >> value >> oL >> oR;
            update(1,1,n);
        }
        else
        {
            cin >> oL >> oR;
            cout << get(1,1,n) << el;
        }
    }   
}


int main()
{
    adhamet

    Sieve();
    int T=1;
    while(T--)
    {
        solve();
    }

    return 0;
}