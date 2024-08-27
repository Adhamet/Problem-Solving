class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size() , col = matrix[0].size();
        vector<vector<int>> t_matrix(col, vector<int>(row));
        for(int r = 0; r < row; r++)
            for(int c = 0; c < col; c++)
                t_matrix[c][r] = matrix[r][c];
        return t_matrix;
    }
};