// Useful maths
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

    string s;
    cin >> s;
    
    if ( s.size() == 1 ) {
        cout << s;
        return 0;
    }

    sort(s.begin(), s.end());

    for (int i = s.size() / 2; i < s.size(); i++) {
        if ( i < s.size() - 1 )
            cout << s[i] << "+";
        else cout << s[i];
    }

    return 0;
}
