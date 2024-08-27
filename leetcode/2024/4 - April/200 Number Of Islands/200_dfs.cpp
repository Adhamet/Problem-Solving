class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        function<bool(int,int)> valid = [&](int x, int y) {
            return (x>=0) && (x<n) && (y>=0) && (y<m);
        };
        
        function<void(int,int)> dfs = [&](int x, int y) {
            if(!valid(x,y) || grid[x][y] == '0' || vis[x][y]) return;

            vis[x][y] = 1;
            dfs(x,y-1);
            dfs(x,y+1);
            dfs(x+1,y);
            dfs(x-1,y);
        };

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
    
};
