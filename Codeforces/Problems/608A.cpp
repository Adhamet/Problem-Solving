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
/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
	int n,s;
    cin >> n >> s;
    pair<int,int> pr;

    for(int i = 0; i < n; i++) {
        cin >> pr.F >> pr.S;
        if ( pr.F + pr.S >= s ) s = pr.F + pr.S;
    }
    cout << s << el;

	return 0;
}
