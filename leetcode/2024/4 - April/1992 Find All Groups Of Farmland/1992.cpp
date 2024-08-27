class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        vector<vector<int>> ans;
        for(int r=0; r<n; r++) {
            for(int c=0; c<m; c++) {
                if(land[r][c]) {
                    int x,y;

                    for(x = r; x<n && land[x][c]; x++)
                        for(y = c; y<m && land[x][y]; y++)
                            land[x][y]=0;
                    
                    ans.push_back({r,c,x-1,y-1});
                }
            }
        }
        return ans;
    }
};
