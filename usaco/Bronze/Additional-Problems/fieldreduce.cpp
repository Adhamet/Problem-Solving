#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
bool comparator(pair<pi,int> a, pair<pi,int> b) {
    if(a.F.S < b.F.S) return true;
    else if(a.F.S > b.F.S) return false;
    return a.F.F < b.F.F;
}
int main()
{
    adhamet;

    int n;  cin >> n;
    vector<pair<pi, int>> v(n);
    vector<pi> pt(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].F.F >> v[i].F.S;
        v[i].S = i;
        pt[i]=v[i].F;
    }
    int mn = INT_MAX;
    vi x,y;
    sort(v.begin(), v.end());
    for(auto &i: v) x.emplace_back(i.S);
    sort(v.begin(), v.end(), comparator);
    for(auto &i: v) y.emplace_back(i.S);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                for(int l = 0; l < 4; l++) {
                    if(i+j>3 || k+l>3) continue;
                    int sX=pt[x[i]].F, bX=pt[x[n-1-j]].F, sY=pt[y[k]].S, bY=pt[y[n-1-l]].S;
                    int cnt = 0;
                    for(int m = 0; m < n; m++) {
                        if(pt[m].F>=sX && pt[m].F<=bX && pt[m].S>=sY && pt[m].S<=bY) continue;
                        cnt++;
                    }

                    if(cnt<=3) mn = min(mn, (bX-sX)*(bY-sY));
                }
            }
        }
    }
    cout << mn << el;
    return 0;
}
