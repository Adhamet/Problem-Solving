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
    adhamet
    
    int n, end = 0, cnt = 0;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) if ( s[i] != '.' ) 
    {
        cnt = i + 1;
        while ( s[i] == 'R' )
            i++;
        end = i + 1;

        if ( s[i] == 'L' ) {
            end = i;
            break;
        }
    }
    cout << cnt << " " << end << el;

    return 0;
}
