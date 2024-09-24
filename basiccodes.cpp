//                    TREE  


// 1)  TO FIND PATH FROM ROOT TO NODE OR NODE TO ROOT OF A BINARY TREE
/* class Solution {
public:
    bool getPath(TreeNode* root, vector<int>& arr, int B) {
        // Base case: if root is NULL, return false
        if (!root) {
            return false;
        }
        
        // Add the current node's value to the path
        arr.push_back(root->val);
        
        // If the current node is the target node, return true
        if (root->val == B) {
            return true;
        }
        
        // Recur for left and right subtrees
        if (getPath(root->left, arr, B) || getPath(root->right, arr, B)) {
            return true;
        }
        
        // If the target node is not found in either subtree, remove the current node
        // from the path and return false
        arr.pop_back();
        return false;
    }
    
    vector<int> solve(TreeNode* A, int B) {
        vector<int> path;
        if (A == NULL) {
            return path;
        }
        
        getPath(A, path, B);
        return path;
    }
};
*/