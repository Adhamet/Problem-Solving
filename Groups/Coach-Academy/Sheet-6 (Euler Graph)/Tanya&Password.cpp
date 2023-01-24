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
vector< intPair > adj[300][300];
int in[300][300], out[300][300];
string ans;

void dfs(int x,int y)
{
    while(!adj[x][y].empty())
    {
        auto a = adj[x][y].back();
        adj[x][y].pop_back();
        dfs(a.F,a.S);
    }
    ans.push_back(y);
}

int main()
{
    adhamet
    int size;
    cin >> size;
    for(int i = 0 ; i < size; i++)
    {
        string tmp;
        cin >> tmp;
        int ch1 = tmp[0], ch2 = tmp[1], ch3 = tmp[2];
        adj[ch1][ch2].push_back({ch2,ch3});
        out[ch1][ch2]++;
        in[ch2][ch3]++;
    }

    intPair xy = {-1,-1};
    int dest = 0;
    for(int i = 0; i < 300; i++)
    {
        for(int j = 0; j < 300; j++)
        {
            if(in[i][j] == out[i][j] + 1)
            {
                dest++;
                if(dest > 1) return cout << "NO\n", 0;
            }
            else if(in[i][j] + 1 == out[i][j])
            {
                if(xy.F != -1)
                    return cout << "NO\n", 0;
                xy.F = i, xy.S = j;
            }
            else if(in[i][j] != out[i][j])
                return cout << "NO\n", 0;
        }
    }

    if(xy.F == -1)
    {
        if(dest != 0)
            return cout << "NO\n", 0;

        for(int i = 0; i < 300; i++)
            for(int j = 0; j < 300; j++)
                if(in[i][j])
                {
                    xy.F = i, xy.S = j;
                    break;
                }
    }

    dfs(xy.F,xy.S);
    ans.push_back(xy.F);

    reverse(ans.begin(),ans.end());
    if(ans.size() != size+2)
        return cout << "NO\n", 0;

    cout << "YES" << el << ans << el;
    return 0;
}