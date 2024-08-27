class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));

        function<bool(int,int)> isValid = [&](int i, int j) {
            return (i>=0 && i<n && j>=0 && j<m);     
        };

        function<bool(int,int,int)> dfs = [&](int i, int j, int k) {
            if(k == word.length()) return true;
            if(!isValid(i,j) || vis[i][j] || board[i][j] != word[k]) return false;
            
            vis[i][j] = true;
            if(dfs(i,j+1,k+1) || dfs(i+1,j,k+1) ||
                dfs(i,j-1,k+1) || dfs(i-1,j,k+1)) {
                    return true;
            }

            vis[i][j] = false;
            return false;
        };

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) if(dfs(i,j,0))
                return true;
        return false;
    }
};
