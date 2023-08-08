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
    
    string s;
    int count=0;
    ll sum;
    cin >> s;

    if ( s.size() == 1 ) {
            cout << 0;
            return 0;
    }

    while(true)
    {
        sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            sum += (s[i] - '0');
        }

        count++;
        if ( sum < 10 )
            break;
        
        s = to_string(sum);
    }

    cout << count;
 
	return 0;
}
