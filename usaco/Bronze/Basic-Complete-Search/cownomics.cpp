#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

void setIO(string name = "") {
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);    
    }
}

int main()
{
    adhamet;
    setIO("cownomics");

    int n, m;
    cin >> n >> m;

    vector<vector<char>> s(n,vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> s[i][j];

    vector<vector<char>> non_s(n,vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> non_s[i][j];

    int pL=0; // potential location
    for(int i = 0; i < m; i++) {
        bool duplicate = false;

        for(int j = 0; j < n; j++) {
            for(int z = 0; z < n; z++) {
                if(s[j][i] == non_s[z][i]) {
                    duplicate = true;
                    break;
                }
            }
        }
        
        if (!duplicate) pL++;
    }

    cout << pL << el;
    
    return 0;
}