/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */ class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        return isMirror(root.left, root.right);
    }

    private boolean isMirror(TreeNode t1, TreeNode t2) {
        // both null → symmetric
        if (t1 == null && t2 == null) return true;
        
        // one null → not symmetric
        if (t1 == null || t2 == null) return false;
        
        // values must match AND subtrees must be mirror
        return (t1.val == t2.val) 
            && isMirror(t1.left, t2.right)
            && isMirror(t1.right, t2.left); 
    }
}