#include <bits/stdc++.h>
#include <climits>
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
vi UP={-1,0}, DOWN={1,0}, LEFT={0,-1}, RIGHT={0,1};
vector<vi> anticlockwise={UP,LEFT,DOWN,RIGHT};
vector<vi> clockwise={UP,RIGHT,DOWN,LEFT};
int n,m,k;
vector<vi> gAns;
void spiral(int i, int j, bool cntr) {
    vector<vi> dirs = cntr? anticlockwise: clockwise;
    int cnt=0, dIdx=0, len=1, remain=1, step=1;
    bool willInc = false;
    while(cnt < n*m) {
        bool out = i<0 || j<0 || i>=n || j>=m;
        if(!out) gAns[i][j]=min(gAns[i][j],step), cnt++;
        step++;
        i+=dirs[dIdx][0], j+=dirs[dIdx][1];
        remain--;
        if(remain == 0) {
            if(willInc) len++;
            dIdx = (dIdx+1)%4;
            remain = len;
            willInc = !willInc;
        }
    }
}

int main()
{
    adhamet;

    cin >> n >> m >> k;
    gAns = vector<vi>(n, vi(m, INT_MAX));
    for(int i = 0; i < k; i++) {
        int r,c,t;  cin >> r >> c >> t;
        spiral(r-1,c-1,t);
    }

    for(auto &row: gAns) {
        for(auto &col : row) cout << col << ' ';
        cout << el;
    }

    return 0;
}
