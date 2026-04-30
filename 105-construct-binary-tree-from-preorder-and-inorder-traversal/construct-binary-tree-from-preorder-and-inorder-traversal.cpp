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

// helper function
TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                vector<int>& inorder, int inStart, int inEnd,
                unordered_map<int,int>& mp){

    // base case
    if(preStart > preEnd || inStart > inEnd)
        return NULL;

    // root from preorder
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    // find root in inorder
    int inRoot = mp[rootVal];

    // number of nodes in left subtree
    int numsLeft = inRoot - inStart;

    // build left subtree
    root->left = build(preorder, preStart + 1, preStart + numsLeft,
                       inorder, inStart, inRoot - 1, mp);

    // build right subtree
    root->right = build(preorder, preStart + numsLeft + 1, preEnd,
                        inorder, inRoot + 1, inEnd, mp);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    unordered_map<int,int> mp;

    // store inorder indices
    for(int i = 0; i < inorder.size(); i++){
        mp[inorder[i]] = i;
    }

    return build(preorder, 0, preorder.size()-1,
                 inorder, 0, inorder.size()-1, mp);
    }
};