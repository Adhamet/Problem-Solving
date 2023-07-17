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

    int n;
    string s;
    vector<int> cnt(26,0);
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < 2 * n - 2; i+=2) {
        cnt[s[i] - 'a']++;
        if (!cnt[s[i+1] - 'A']) ans++;
        else cnt[s[i+1] - 'A']--;
    }
    cout << ans << el;

    return 0;
}
