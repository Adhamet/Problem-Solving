#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
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
    setIO("cowtip");
    adhamet;

    int n, tipped = 0;  cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char x; cin >> x;
            if(x == '1') board[i][j]=1, tipped++;
        }
    }

    int flips = 0;
    while(tipped!=0) {
        int fi=0,fj=0,maxdist=0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j]==1) if(i+j>maxdist) {
                    maxdist=i+j;
                    fi=i, fj=j;
                }
            }
        }

        for(int i = 0; i <= fi; i++) {
            for(int j = 0; j <= fj; j++) {
                if(board[i][j]==0) board[i][j]=1, tipped++;
                else board[i][j]=0, tipped--;
            }
        }
        flips++;
    }
    cout << flips;

    return 0;
}
