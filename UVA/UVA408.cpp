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
const int MXN = 501;

void solve()
{
    int index = 0, mod, step;
    while( cin >> step >> mod )
    {
        bool vis[mod] = {0};
        bool bad = false;
        for(int i = 0; i < mod; i++)
        {
            int generated = (index + step) % mod;
            if( vis[generated] == 1 ) { bad = true; break; }
            vis[generated] = 1;
            index = generated;
        }
        cout << setw(10) << step << setw(10) << mod << "    ";
        bad? cout << "Bad Choice\n\n" : cout << "Good Choice\n\n";
    }
}

int main()
{
    adhamet

    solve();
    return 0;
}