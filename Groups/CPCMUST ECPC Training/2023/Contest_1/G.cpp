#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
 
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    bool flag = true;
    if (s.size() == 1)
    {
        cout << s;
        return;
    }

    int i = s.size()-2;
    while (flag)
    {
        if (s[i] == '1' && s[i+1] == '0')
        {
            if (i+2 < s.size())
            {
                if (s[i+2]=='0') {
                    s.erase(i+1,1);
                    i--;
                }
                else if (s[i+2] == '1') {
                    s.erase(i,1);
                    i--;
                }
            }
        }
        i--;

        if (i == 0)
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (j == s.size() - 2 && s[i] == '1' && s[i+1] == '0') {
                    i = s.size() - 2;
                }
            }
        }
    }
    cout << s << endl;
}
 
int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
 
	return 0;
}
