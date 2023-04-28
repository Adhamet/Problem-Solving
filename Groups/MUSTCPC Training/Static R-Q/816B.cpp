// Karen and Coffee
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

const int N = 200002;
int arr[N]{0};
int main()
{
    //adhamett
    
    int n,k,q;
    cin >> n >> k >> q;
    
    for(int i = 0; i < n; i++) {
        int l,r;
        cin >> l >> r;
        arr[l]++, arr[r+1]--;
    }

    for(int i = 1; i < N; i++) arr[i] += arr[i-1];
    for(int i = 1; i < N; i++) arr[i] = (arr[i] >= k ? 1 : 0);
    for(int i = 1; i < N; i++) arr[i] += arr[i-1];

    while(q--)
    {
        int l,r;
        cin >> l >> r; l--;
        cout << arr[r] - arr[l] << el;
    }

    return 0;
}