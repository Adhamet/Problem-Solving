#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define ull unsigned long long
#define F first
#define S second
#define el '\n'

const int N = 1e7+5, oo = 1e9+7, MOD=1e9+7;
int n,m;

int main()
{
    adhamet
    int T;
    cin >> T;
    for(int itr = 0; itr < T; itr++)
    {
        int size;   
        cin >> size;

        if(size == 0){
            cout << "Case " << itr+1 << ": " << 0 << el;
            continue;
        }

        vector<ull> numbers(size), dp(size);
        for(int i = 0; i < size; i++)   
            cin >> numbers[i];

        
        dp[0] = numbers[0];
        dp[1] = max(dp[0], numbers[1]);

        for(int i = 2; i < size; i++)
            dp[i] = max(dp[i-1], numbers[i] + dp[i-2]);

        cout << "Case " << itr+1 << ": " << dp[size-1] << el;
    }

    return 0;
}