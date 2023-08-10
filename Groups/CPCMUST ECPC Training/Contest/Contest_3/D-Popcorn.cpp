#include "bits/stdc++.h"
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
    //freopen("popcorn.in", "r", stdin);
    
    adhamet;
    
    int t;
    cin >> t;
    while(t--) {
        int n,r;
        cin >> n >> r;
        double sum=1;
        for(int i = 1; i <= r; i++)
            sum = sum * (n - r + i) / i;
        cout << (int)sum << endl;
    }
 
	return 0;
}
