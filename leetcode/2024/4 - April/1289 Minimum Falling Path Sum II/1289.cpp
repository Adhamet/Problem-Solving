class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j = 0; j < n; ++j) {
            dp[0][j] = grid[0][j];
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int temp = INT_MAX;

                for(int k = 0; k < n; ++k) {
                    if(k != j) {
                        temp = min(temp, grid[i][j] + dp[i - 1][k]);
                    }

                    dp[i][j] = temp;
                }
            }
        }

        for(int j = 0; j < n; ++j) {
            ans = min(ans, dp[n - 1][j]);
        }

        return ans;
    }
};


/* FAILED DFS SOLUTION
class Solution {
public:
    int n,m;
    vector<int> values;
    vector<vector<bool>> vis;
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<bool>(m));

        for(int i = 0; i < m; i++) {
            dfs(0, i, 0, grid);
        }

        int minEle = INT_MAX;
        for(auto ele: values) minEle = minEle > ele? ele: minEle;
        return minEle;
    }

    bool valid(int x, int y) {
        return x>=0 && x<n && y>=0 && y<m;
    }

    void dfs(int x, int y, int val, vector<vector<int>>& grid) {
        if(x == n) {
            values.push_back(val);
            return;
        } else if(!valid(x,y) || vis[x][y]) {
            return;
        }

        vis[x][y] = true;
        for(int j = 0; j < m; j++) if(m==1 || y!=j) {
            dfs(x+1, j, val+grid[x][j], grid);
        }
        vis[x][y] = false;
    }
};
*/
