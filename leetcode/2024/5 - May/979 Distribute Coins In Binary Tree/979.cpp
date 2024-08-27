/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }

    int dfs(TreeNode* curr, int& moves) {
        if(curr == nullptr) return 0;

        int leftCoins = dfs(curr->left, moves);
        int rightCoins = dfs(curr->right, moves);

        moves += abs(leftCoins) + abs(rightCoins);

        return (curr->val - 1) + leftCoins + rightCoins;
    }
};
