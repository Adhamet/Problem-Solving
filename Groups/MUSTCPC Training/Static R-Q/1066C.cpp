// Kuriyama Mirai's Stones
#include <bits/stdc++.h>
 
using namespace std;
#define adhamett ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

const int N = 2e5 + 10;
int arr[N];

void solve()
{
    int l=1, r=0, x;
    int q;
    cin >> q;
    char op;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> op >> x;
        if (op == 'L')
            arr[x] = --l;
        else if (op == 'R')
            arr[x] = ++r;
        else if (op == '?')
            cout << min(arr[x] - l, r - arr[x]) << el;
    }    
}

int main()
{
    adhamett
    
    solve();

    return 0;
}