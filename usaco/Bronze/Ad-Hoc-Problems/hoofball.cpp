#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
int dist[100], touch[100];
int target(int i) {
    if(i==0) return 1;
    if(i==n-1) return n-2;
    if(dist[i]-dist[i-1] <= dist[i+1]-dist[i]) return i-1;
    else return i+1;
};

int main()
{
    setIO("hoofball");
    adhamet;

 	cin >> n;
    for(int i = 0; i < n; i++) cin >> dist[i];

    sort(dist, dist+n);
    for(int i = 0; i < n; i++) touch[target(i)]++;

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(touch[i]==0) cnt++;
        if(touch[i]==1 && touch[target(i)]==1 && target(target(i)) == i) { // oscillation
            touch[target(i)] = -999;
            cnt++;
        }
    }
    cout << cnt << el;

    return 0;
}
