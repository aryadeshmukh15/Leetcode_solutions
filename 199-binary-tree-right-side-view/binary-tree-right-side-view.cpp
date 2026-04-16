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
 */ class Solution {
public:

// DFS helper function
void solve(TreeNode* root, int level, vector<int>& ans){

    // Base case
    if(root == NULL)
        return;

    // If first node at this level
    // add to answer
    if(level == ans.size()){
        ans.push_back(root->val);
    }

    // Go right first (important for right view)
    solve(root->right, level + 1, ans);

    // Then go left
    solve(root->left, level + 1, ans);
}


vector<int> rightSideView(TreeNode* root) {
    
    vector<int> ans;

    // Start DFS from level 0
    solve(root, 0, ans);

    return ans;

    }
};