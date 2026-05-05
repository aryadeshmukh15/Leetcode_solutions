/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
     
    if(root == NULL) return "";

    string s = "";

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        TreeNode* node = q.front();
        q.pop();

        if(node == NULL){
            s += "null,";
            continue;
        }

        // store value
        s += to_string(node->val) + ",";

        // push children (even if null)
        q.push(node->left);
        q.push(node->right);
    }

    return s;
}
    
     // Decodes your encoded data to tree
TreeNode* deserialize(string data) {

    if(data.size() == 0) return NULL;

    // split string by ','
    stringstream ss(data);
    string str;

    getline(ss, str, ',');
    TreeNode* root = new TreeNode(stoi(str));

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        TreeNode* node = q.front();
        q.pop();

        // left child
        getline(ss, str, ',');
        if(str == "null"){
            node->left = NULL;
        } else {
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        // right child
        getline(ss, str, ',');
        if(str == "null"){
            node->right = NULL;
        } else {
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));