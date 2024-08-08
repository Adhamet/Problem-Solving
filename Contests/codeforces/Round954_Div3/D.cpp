#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;   cin >> s;
        int ans;
        for(int i = 0; i < n-1; i++) {
            int cnt=stoi(s.substr(i,2));
            for(int j = i-1; j>=0; j--) {
                cnt=min(cnt*(s[j]-'0'), cnt+(s[j]-'0'));
            }
            for(int j =i+2; j<n;j++) {
                cnt=min(cnt*(s[j]-'0'), cnt+(s[j]-'0'));
            }
            ans = min(ans,cnt);
        }
        cout << ans;
    }

    return 0;
}
