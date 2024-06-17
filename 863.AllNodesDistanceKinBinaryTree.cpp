/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void visited(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        visited(root, parentMap);
        unordered_map<TreeNode*, bool> visitedMap;
        queue<TreeNode*> q;
        q.push(target);
        visitedMap[target] = true;
        int dist = 0;
        
        while (!q.empty()) {
            int size = q.size();
            if (dist++ == k) break;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !visitedMap[node->left]) {
                    q.push(node->left);
                    visitedMap[node->left] = true;
                }
                if (node->right && !visitedMap[node->right]) {
                    q.push(node->right);
                    visitedMap[node->right] = true;
                }
                if (parentMap[node] && !visitedMap[parentMap[node]]) {
                    q.push(parentMap[node]);
                    visitedMap[parentMap[node]] = true;
                }
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
        }
        
        return result;
    }
};
