#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main() 
{
    adhamet;

    int n;
    cin >> n;
    int ans[n];
    vector<pair<pii,int>> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i].F.F >> vec[i].F.S;
        vec[i].S = i;
    } sort(vec.begin(), vec.end());

    int rooms = 0, last_room = 0;
    priority_queue<pii> pq;
    for(int i = 0; i < n; i++) {
        if(pq.empty()) {
            last_room++;
            pq.push(make_pair(-vec[i].F.S, last_room));
            ans[vec[i].S] = last_room;
        } else {
            pii min = pq.top();
            if(-min.first < vec[i].F.F) {
                pq.pop();
                pq.push(make_pair(-vec[i].F.S, min.S));
                ans[vec[i].S] = min.S;
            } else {
                last_room++;
                pq.push(make_pair(-vec[i].F.S, last_room));
                ans[vec[i].S]=last_room;
            }
        }
        rooms = max(rooms, int(pq.size()));
    }
    cout << rooms << el;
    for(int i = 0; i < n; i++) cout << ans[i] << " ";

    return 0;
}

