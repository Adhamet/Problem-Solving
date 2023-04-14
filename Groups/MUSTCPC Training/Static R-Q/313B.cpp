// Ilya and Queries
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

const int N = 1e6;
int prefix[N]{0};
int main()
{
    adhamet
    
    int q;
    string s;
    cin >> s >> q;

    int len = s.size();
    for(int i = 1; i < len; i++) if(s[i] == s[i-1])
            prefix[i]++;
    
    for(int i = 1; i < len; i++) {
            prefix[i] += prefix[i-1];
            cout << prefix[i] << " ";
    }
    cout << el;
    while(q--)
    {
        int l,r;
        cin >> l >> r;

        cout << prefix[--r] - prefix[--l] << el;
    }

    return 0;
}