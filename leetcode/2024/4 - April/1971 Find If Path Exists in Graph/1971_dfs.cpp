class Solution {
public:
    vector<int> adjL[(int)2e5+5];
    bool vis[(int)2e5+5];
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(const auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }

        return dfs(source, destination);
    }

    bool dfs(int node, int destination) {
        if(node == destination) return true;

        vis[node] = true;
        for(int child: adjL[node]) if(!vis[child]) {
            if(dfs(child, destination)) return true;
        }
        return false;
    }
};
