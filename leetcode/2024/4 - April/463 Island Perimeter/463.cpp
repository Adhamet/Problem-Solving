class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;

        function<bool(int,int)> valid = [&](int x, int y) {
            return (x>=0) && (x<n) && (y>=0) && (y<m);
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    perimeter += 4;

                    if (valid(i-1,j) && grid[i-1][j] == 1) perimeter--;
                    if (valid(i+1,j) && grid[i+1][j] == 1) perimeter--;
                    if (valid(i,j-1) && grid[i][j-1] == 1) perimeter--;
                    if (valid(i,j+1) && grid[i][j+1] == 1) perimeter--;
                }
            }
        }

        return perimeter;
    }
};
