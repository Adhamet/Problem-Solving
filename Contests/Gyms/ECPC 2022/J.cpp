#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll  = long long;

struct Event {
    int time;
    int type; // 0 = add, 1 = coin, 2 = remove
    int x;    // node for add/remove/coin
    int qi;   // coin’s query‐index (only for type=1)
    bool operator<(Event const& o) const {
        if (time != o.time) return time < o.time;
        return type < o.type; 
        // we want add(0) before coin(1) before remove(2) at the same time
    }
};

int N, Q;
vector<vector<int>> g;
vector<int> tin, tout, depth, euler_to_node;
int timer;

// 1) Build tin/tout via DFS
void dfs(int u, int p, int d){
    depth[u] = d;
    tin[u] = timer;
    euler_to_node[timer++] = u;
    for(int v: g[u]) if(v!=p){
        dfs(v,u,d+1);
    }
    tout[u] = timer-1;
}

// 2) Segment‐tree with per‐node multiset<pii(depth, node_id)>
vector<multiset<pii>> seg;

// insert/remove a magnet‐tag over [L..R]
void update_range(int idx, int L, int R, int ql, int qr, pii tag, bool add){
    if (qr < L || R < ql) return;
    if (ql <= L && R <= qr){
        if (add)      seg[idx].insert(tag);
        else {
            auto it = seg[idx].find(tag);
            if (it!=seg[idx].end()) seg[idx].erase(it);
        }
        return;
    }
    int mid = (L+R)>>1;
    update_range(idx<<1,   L,    mid, ql, qr, tag, add);
    update_range(idx<<1|1, mid+1, R,   ql, qr, tag, add);
}

// point‐query at position p: walk root→leaf, collect max over all visited multisets
pii query_point(int idx, int L, int R, int p){
    pii best = {-1,-1};
    if (!seg[idx].empty()){
        // largest by depth is in rbegin()
        best = *prev(seg[idx].end());
    }
    if (L==R) return best;
    int mid=(L+R)>>1;
    if (p<=mid)  best = max(best, query_point(idx<<1,   L,    mid, p));
    else         best = max(best, query_point(idx<<1|1, mid+1, R,   p));
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        cin >> N >> Q;
        g.assign(N+1,{});
        for(int i=0,u,v;i<N-1;i++){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        tin .assign(N+1,0);
        tout.assign(N+1,0);
        depth.assign(N+1,0);
        euler_to_node.assign(N,0);
        timer = 0;
        dfs(1,0,0);

        // build empty segment tree
        seg.assign(4*N, {});

        // read queries & build event list
        vector<Event> ev;
        ev.reserve(Q*2);

        int coinCount = 0;
        for(int i=0;i<Q;i++){
            int tp; 
            cin >> tp;
            if (tp==1){
                int x,t1,t2;
                cin >> x >> t1 >> t2;
                // add at t1
                ev.push_back({t1, 0, x, -1});
                // remove at t2+1
                ev.push_back({t2+1, 2, x, -1});
            } else {
                int x,t;
                cin >> x >> t;
                ev.push_back({t, 1, x, coinCount++});
            }
        }

        sort(ev.begin(), ev.end());

        vector<int> ans(coinCount, -1);

        // sweep through events in time‐order
        for(auto &e : ev){
            if (e.type==0){
                // add a magnet at node x
                int u = e.x;
                pii tag = { depth[u], u };
                update_range(1, 0, N-1, tin[u], tout[u], tag, true);
            }
            else if (e.type==2){
                // remove that magnet
                int u = e.x;
                pii tag = { depth[u], u };
                update_range(1, 0, N-1, tin[u], tout[u], tag, false);
            }
            else {
                // coin‐query at node x
                int u = e.x;
                pii best = query_point(1, 0, N-1, tin[u]);
                ans[e.qi] = (best.first<0 ? -1 : best.second);
            }
        }

        // output in original coin‐query order
        for(int x: ans){
            cout << x << "\n";
        }
    }
    return 0;
}

