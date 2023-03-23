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
    int n,x;
    cin >> n;
    stack<int> maxPts;
    deque<int> result;
    int arr[n];

    int mx = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if( mx < arr[i] ) {
            mx = arr[i];
            maxPts.push(mx);
        }
    }

    for(int i = n-1; i >= 0; i--)
    {
        if(arr[i] == maxPts.top())
        {
            maxPts.pop();
            result.push_front(arr[i]);
            while(!result.empty())
            {
                cout << result.front() << " ";
                result.pop_front();
            }
        }
        else { result.push_front(arr[i]); }
    }
    cout << el;
}

int main()
{
    adhamet
 
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
 
    return 0;
}