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
    int s,x,tmp;
    cin >> s;
    tmp = s;
    vector<int> vec(s);
    stack<int> stk;

    for(int i = 1; i <= s; i++)
    {
        cin >> vec[i];
        if(i == 1) {
            stk.push(vec[i])
        }
        if (vec[i] == tmp)
            while(!stk.empty())
            {
                tmp--;
                cout << stk.top();
                stk.pop();
            }    
        else {
            stk.push(vec[i]);
            cout << endl;
        }
    }
}

int main()
{
    //adhamet

    solve();

    return 0;
}