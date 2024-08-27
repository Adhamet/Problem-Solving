class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adjL[(int)2e5+5];
        bool vis[(int)2e5+5];
        memset(vis, false, (int)2e5+5);

        for(const auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }

        queue<int> q;
        q.push(source);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(node == destination) return true;
            for(int child: adjL[node]) if(!vis[child]) {
                vis[child] = true;
                q.push(child);
            }
        }
        return false;
    }
};
