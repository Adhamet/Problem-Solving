class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};

        vector<list<int>> adjL(n);
        vector<int> deg(n,0);

        for(const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        
        queue<int> leaves;
        for(int i = 0; i < n; i++) if(deg[i] == 1)
            leaves.push(i);
        
        int rmNodes = n;
        while(rmNodes > 2) {
            int cnt = leaves.size();
            rmNodes -= cnt;
            for(int i = 0; i < cnt; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for(int child: adjL[leaf]) if(--deg[child]==1)
                    leaves.push(child);
            }
        }

        vector<int> res;
        while(!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }
        return res;
    }
};
