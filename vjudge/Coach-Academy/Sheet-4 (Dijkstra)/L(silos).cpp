        #include <bits/stdc++.h>
        using namespace std;

        #define ll long long
        #define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        #define F first
        #define S second
        #define intPair pair<int,int>
        const int N = 1e5+10, oo = 1e9+7;
        int n,m,cap,l;
        int dist[N];  
        vector<intPair> adj[N];

        void Dijkstra()     
        {
            priority_queue< intPair, vector<intPair>, greater<intPair> > pq;
            dist[cap] = 0;
            pq.push({0,cap});
            while(!pq.empty())
            {
                auto top = pq.top();
                pq.pop();

                if (top.F != dist[top.S]) continue;
                for (auto child: adj[top.S])
                {
                    auto ch = child.F, chC = child.S;
                    if(dist[top.S] + chC < dist[ch])
                    {
                        dist[ch] = dist[top.S] + chC;
                        pq.push({dist[ch],ch});
                    }
                }
            }
        }


        int main()
        {
            fff
            cin >> n >> m >> cap;
            cap--;
            memset(dist,oo,sizeof(dist));
            for(int i=0; i < m; i++)
            {
                int u,v,c;
                cin >> u >> v >> c;
                u--,v--;
                adj[u].push_back( {v,c} );
                adj[v].push_back( {u,c} );
            }
            cin >> l;
            Dijkstra();
            int r = 0;

            set<pair<intPair,int>> st;
            for(int i=0; i<n; i++)
            {
                if(dist[i] == l) r++;
                for(auto neigh: adj[i])
                {
                    st.insert({{min(i,neigh.F),max(i,neigh.F)}, neigh.S});
                }
            }

            
            for(auto pair: st)
            {
                int i = pair.F.F;
                int v = pair.F.S;            
                if(dist[i]<l && dist[v]<l && dist[i]+dist[v]+pair.S == 2*l) r++;
                else if(dist[i]+dist[v]+pair.S > 2*l){
                    if (dist[i]<l && dist[i]+pair.S > l) r++;
                    if (dist[v]<l && dist[v]+pair.S > l) r++;
                }
            } 
            cout << r << '\n';
        }
