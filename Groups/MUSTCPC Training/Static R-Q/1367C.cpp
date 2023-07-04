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
    int n,k;
    cin >> n >> k;

    string s; cin >> s;

    ll lastId = 0, count = 0;

    string temp = s;
    temp[0] = '1';

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
        {
            count++;

            if (count > k)
            {
                temp[i] = '1';
                lastId = i;
                count = 0;
            }
        }
        else
        {
            if (count < k) temp[lastId] = '0';
            count = 0;
        }
    }

    ll res = 0;

    for (int i = 0; i < n; i++)
        if (temp[i] != s[i])
            res++;
    cout << res << endl;
}

int main()
{
    adhamett

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
