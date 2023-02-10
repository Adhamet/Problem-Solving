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
    int num,mn = INT_MAX, nCnt = 0;
    int64_t sum = 0;

    cin >> num;
    vector<int> vec(num);

    for(int i = 0; i < num; i++) {
        cin >> vec[i];
        mn = min(mn, abs(vec[i]));
        if(vec[i] < 0) nCnt++;
        sum += abs(vec[i]);
    }
    if(mn == 0) cout << sum << endl;
    else if(nCnt & 1) cout << sum - 2*mn << endl;
    else cout << sum << endl;
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