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
    string smallestFromLeaf(TreeNode* root) {
        string rootStr = ""; rootStr += char(root->val+'a');
        
        dfs(root, rootStr);
        for(string& ans: answers) reverse(ans.begin(),ans.end());

        string a = ""; a += char('z'+1);
        for(string ans: answers) if(ans < a) a = ans;
        return a;
    }
    void dfs(TreeNode* node, string str) {
        if(!node->left && !node->right) {
            answers.push_back(str);
            return;
        }

        if(node->left) dfs(node->left, str+char(node->left->val+'a'));
        if(node->right) dfs(node->right, str+char(node->right->val+'a'));
    }
};
