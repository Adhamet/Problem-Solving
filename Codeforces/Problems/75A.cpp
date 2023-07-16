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
    adhamet

    int n,k,sum;
    cin >> n >> k;

    sum = n + k;
    string a,b,c;
    a=to_string(n);
    b=to_string(k);
    c=to_string(sum);

    string at,bt,ct;

    for(int i = 0; i < a.size(); i++)
        if (a[i] != '0') at.push_back(a[i]);
    for(int i = 0; i < b.size(); i++)
        if (b[i] != '0') bt.push_back(b[i]);
    for(int i = 0; i < c.size(); i++)
        if (c[i] != '0') ct.push_back(c[i]);
    int ati = stoi(at);
    int bti = stoi(bt);
    int cti = stoi(ct);
    if ( ati + bti == cti ) cout << "YES" << el;
    else cout << "NO" << el;

    return 0;
}
