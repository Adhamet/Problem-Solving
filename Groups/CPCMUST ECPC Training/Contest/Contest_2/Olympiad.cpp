#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
 
int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
        int n,l,r,x,cnt=0;
    cin>>n>>l>>r>>x;
    int arr[n];

    for(int i=0; i<n; i++)cin>>arr[i];
 
    vector<vector<int>>ans;
    for(int msk=0; msk<(1<<n); msk++){
        int mn=INT_MAX,mx=-INT_MAX;
        vector<int>temp;
        int sum = 0;
        for(int i=0; i<n; i++){
            if((msk>>i)&1){
                if(arr[i]<mn) mn=arr[i];
                if(arr[i]>mx) mx=arr[i];
                temp.push_back(arr[i]);
                sum += arr[i];
            }
        }
        if((sum>=l&&sum<=r)&&(abs(mn-mx)>=x)&&temp.size()>=2)
        {
            ans.push_back(temp);
            cnt++;
        }
        //ans.insert(temp);
    }
    cout<<cnt;
 
	return 0;
}
