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

/* 
void solve()
{
    int n, mx = INT_MIN;
    cin >> n;
    deque<intPair> greats;
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(i == 0) continue;
    
        if(mx < arr[i])
        {
            mx = arr[i];
            greats.push_back( {mx,i} );
        }
        else mx = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(!greats.empty())
        {
            bool flag = 1;
            if(arr[i] < greats.front().F )
                cout << greats.front().F << " ";
            else if(arr[i] >= greats.front().F)
            {
                for(int j = 0; j < greats.size(); j++) {
                    if(arr[i] < greats[j].F) { cout << greats[j].F << " "; flag = 0; break; }
                }
                if(flag) cout << "-1 ";
            }
            
            if(i == greats.front().S - 1) { greats.pop_front(); }
            continue;
        }
        (i == n-1) ? cout << "-1": cout << "-1 ";
    }
}
*/

int main()
{
    adhamet
    
    // solve();
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans[n];
    stack<int> stk;

    for(int i = n-1; i >= 0; i--)
    {
        while(!stk.empty() && stk.top() <= arr[i])
            stk.pop();
        if(stk.empty())
            ans[i] = -1;
        else
            ans[i] = stk.top();
        stk.push(arr[i]);
    }
    
    for(int i=0; i < n;i++)
        cout << ans[i] << " ";
    return 0;
}