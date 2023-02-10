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
    int num,i,j,result=0;
    cin >> num;
    string str;
    cin >> str;
    for(i = 0; i < num-1; i++)
    {
        j = num-i-1;
        if( (str[i] == '0' && str[j] == '1') || (str[i] == '1' && str[j] == '0') )
        {
            result+=2;
            continue;
        }
        break;
    }    
    int res = num - result;
    if(num-result<0) res = 0;
    cout << res ? num-result: 0 << el;
}

int main()
{
    adhamet
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}