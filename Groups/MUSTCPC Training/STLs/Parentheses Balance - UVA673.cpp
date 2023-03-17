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
 
void solve()
{
    string input;
    getline(cin, input);
    if(input.empty()) { cout << "Yes\n"; return; }
    stack<char> stk;
    bool no=0;
    for(int i = 0; i < input.length(); i++) 
    {
        if(input[i] == '(' || input[i] == '[') stk.push(input[i]);
        else {
            if(!stk.empty() && stk.top() == '(' && input[i] == ')')
                stk.pop();
            else if (!stk.empty() && stk.top() == '[' && input[i] == ']')
                stk.pop();
            else { no=1; break; }
        }
    }
    ( no == 1 || !stk.empty() ) ? cout << "No\n": cout << "Yes\n";
}
 
int main()
{
    //adhamet
 
    int T;
    cin >> T; getchar();
    while(T--) {
        solve();
    }
 
    return 0;
}