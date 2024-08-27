#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
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

int n;
vector<int> poss;
int solve(int i, int dir) {
    int r = 1, prev = i;
    while(true) {
        int nxt = prev;
        while(nxt + dir >= 0 && nxt + dir < n && abs(poss[nxt+dir]-poss[prev]) <= r) {
            nxt += dir;
        }

        if(nxt==prev) break;

        r++;
        prev=nxt;
    }
    return abs(prev-i);
}

int main() {
    setIO("angry");
    adhamet;
    
    cin >> n;
    poss.resize(n);
    for(int i = 0; i < n; i++) cin >> poss[i];

    sort(poss.begin(),poss.end());

    int mx=0;
    for(int i = 0; i < n; i++) {
        mx = max(mx, solve(i,-1) + solve(i,1) + 1);
    }
    cout << mx << el;

    return 0;
}

