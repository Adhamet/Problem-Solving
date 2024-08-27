class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjL;
        vector<int> ans(n,0);
        vector<int> count(n,1);

        function<void(int, int)> dfs = [&](int node, int parent) {
            for(int child: adjL[node]) if(child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        };

        function<void(int, int)> dfs2 = [&](int node, int parent) {
            for(int child: adjL[node]) if(child != parent) {
                ans[child] = ans[node] - count[child] + (count.size() - count[child]);
                dfs2(child,node);
            }
        };

        

        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }

        dfs(0,-1), dfs2(0,-1);

        return ans;
    }
};
