// Ilya and Queries
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

int main()
{
    adhamett
    
    int q;
    string s;
    cin >> s >> q;

    int len = s.size();
    int arr[len]{0};
    for(int i = 1; i < len; i++) {
        if(s[i] == s[i-1])
            arr[i]++;
        arr[i] += arr[i-1];
    }

    while(q--)
    {
        int l,r;
        cin >> l >> r;

        cout << arr[--r] - arr[--l] << el;
    }

    return 0;
}