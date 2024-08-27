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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        TreeNode *res = dfs(root, val, depth);
        return res;
    }

    TreeNode* dfs(TreeNode *currNode, int val, int depth) {
        if (currNode == nullptr)
            return currNode;
        
        if (depth == 2) {
            TreeNode *newLeftNode = new TreeNode(val);
            TreeNode *newRightNode = new TreeNode(val);
            newLeftNode->left = currNode->left;
            newRightNode->right = currNode->right;
            currNode->left = newLeftNode;
            currNode->right = newRightNode;
            return currNode;
        }
        
        currNode->left = dfs(currNode->left, val, depth - 1);
        currNode->right = dfs(currNode->right, val, depth - 1);
        return currNode;
    }
};