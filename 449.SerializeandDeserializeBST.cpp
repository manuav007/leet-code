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
        if(!root) return "";
        string s = "";
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* node = qu.front();a
            qu.pop();
            if(node == NULL) {
                s.append("#,");
            } else {
                s.append(to_string(node->val) + ",");
                qu.push(node->left);
                qu.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> qu;
        qu.push(root);
        
        while(!qu.empty()){
            TreeNode* node = qu.front();
            qu.pop();
            
            if(getline(s, str, ',')) {
                if(str == "#") {
                    node->left = NULL;
                } else {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    qu.push(leftNode);
                }
            }
            
            if(getline(s, str, ',')) {
                if(str == "#") {
                    node->right = NULL;
                } else {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    qu.push(rightNode);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
