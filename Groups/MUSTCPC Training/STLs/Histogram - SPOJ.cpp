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
 
void solve(int n)
{
    int arr[n];
    ll area;
    stack<int> stk;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(stk.empty())
            area = arr[stk.top()] * i;
        else
            area = arr[stk.top()] * (i - stk.top() - 1);
    }

    


}
 
int main()
{
    //adhamet
 
    int T;
    while(cin >> T && T != 0) {
        solve(T);
    }
 
    return 0;
}