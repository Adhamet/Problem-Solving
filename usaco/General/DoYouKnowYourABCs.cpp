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
    adhamet;
    
    int arr[7];
    for(int i = 0; i < 7; i++) cin >> arr[i];
    sort(arr,arr+7);

    cout << arr[0] << " " << arr[1] << " ";
    for(int i = 0; i < 4; i++)
        if(arr[0] + arr[1] + arr[2+i] == arr[6]) cout << arr[2+i];

    return 0;
}
