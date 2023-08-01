#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

int solve() {
    string str;
    stack<int> s;
    cin >> str;
    int closed=0,openned=0,cnt=0;
    for(int i = 0; i < str.size(); i++) {
        if (str[i] == '(') openned++;
        else if (str[i] == ')') closed++;
    }

    int l = str.size() - 1;
    for(int i=0;i<str.size();i++)
    {
            if(s.empty())
            {
                s.push(str[i]);
                continue;
            }
            if(str[i]==')'&&s.top() =='(')
            {
                s.pop();
            }
            else
            {
                s.push(str[i]);
            }
    }

    if ( closed != openned ) return cout << -1 << el, 0;
    
    cout << s.size()/2 << el;

    return 0;
}
int main() 
{
/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    int t;
    cin >> t;
    while(t--) 
        solve();

	return 0;
}
