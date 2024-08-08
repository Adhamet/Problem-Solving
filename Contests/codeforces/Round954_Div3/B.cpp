#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int n,m;
bool valid(int i,int j) {
    return i>=0 && i<n && j>=0 && j<m;
}
int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        cin >> n >> m;
        int grid[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int t=0,b=0,l=0,r=0,val=grid[i][j];
                if(valid(i-1,j)) l=grid[i-1][j];
                if(valid(i+1,j)) r=grid[i+1][j];
                if(valid(i,j-1)) t=grid[i][j-1];
                if(valid(i,j+1)) b=grid[i][j+1];
                if(val>l && val>r && val>t && val>b) {
                    val = max(l,max(r,max(b,t)));
                    grid[i][j] = val;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << grid[i][j] << " ";
            }
            cout << el;
        }
    }

    return 0;
}
