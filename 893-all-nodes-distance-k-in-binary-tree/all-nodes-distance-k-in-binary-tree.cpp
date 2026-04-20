/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */ class Solution {
public:

    // Step 1: Store parent of each node
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // Store parent mapping
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);
        
        // Visited map
        unordered_map<TreeNode*, bool> visited;
        
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        
        int currLevel = 0;
        
        while(!q.empty()) {
            
            int size = q.size();
            
            // Stop when we reach K distance
            if(currLevel++ == k) break;
            
            for(int i = 0; i < size; i++) {
                
                TreeNode* node = q.front();
                q.pop();
                
                // Left
                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                // Right
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                // Parent
                if(parent[node] && !visited[parent[node]]) {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        
        vector<int> result;
        
        // Remaining nodes in queue are answer
        while(!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
};