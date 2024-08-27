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
    vector<string> answers;
    int sumNumbers(TreeNode* root) {
        dfs(root, "");
        int total_ans = 0;
        for(string ans: answers) {
            total_ans += stoi(ans);
        }
        return total_ans;
    }
    void dfs(TreeNode* node, string num) {
        if(node==nullptr) return;
        
        num += to_string(node->val);
        if(!node->left && !node->right)
            answers.push_back(num);
        if(node->left)
            dfs(node->left, num);
        if(node->right)
            dfs(node->right, num);
    }
};

