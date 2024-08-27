class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}}; // Corrected directions
        queue<pair<int,int>> q;

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) { // Corrected loop condition
                if(grid[i][j] == '1') {
                    cnt++;
                    q.push({i,j});

                    while(!q.empty()) {
                        auto [x,y] = q.front();
                        q.pop();

                        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != '1')
                            continue;
                        
                        grid[x][y] = '0';

                        for(auto &dir: dirs) {
                            int nx = x+dir.first;
                            int ny = y+dir.second;
                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == '1')
                                q.push({nx,ny});
                        }
                    }
                }
            }
        }

        return cnt;
    }
};

