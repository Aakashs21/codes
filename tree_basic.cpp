// BT BT BT BT BINARY TREE BINARY TREE BT BT BT BT

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



// ITERATIVE LEVEL ORDER TRAVERSAL BFS OF A BINARY TREE


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;  // Result vector to store each level's nodes
        if (root == nullptr) return ans;  // Edge case: If root is null, return empty vector

        queue<TreeNode*> q;  // Queue to support BFS
        q.push(root);  // Start with the root node

        // BFS loop
        while (!q.empty()) {
            int size = q.size();  // Get the number of nodes at the current level
            vector<int> level;  // Temporary vector to store nodes at the current level

            // Iterate over all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();  // Get the front node from the queue
                q.pop();  // Remove it from the queue

                level.push_back(node->val);  // Add the node's value to the current level

                // Push the left child if it exists
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                // Push the right child if it exists
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            ans.push_back(level);  // Add the current level to the result
        }

        return ans;  // Return the level-order traversal
    }
};





// ITERATIVE PREORDER POSTORDER INORDER IN A SINGLE GO 


class Solution {
public:
    // Function to perform preorder, inorder, and postorder traversal in a single pass
    vector<vector<int>> preInPostTraversal(TreeNode* root) {
        // Vectors to store the results of pre, in, and postorder traversals
        vector<int> pre, in, post;
        if (root == nullptr) return {pre, in, post};  // Return empty vectors if the root is null

        // Stack to store pairs of (TreeNode*, int) where int indicates the state of the node
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});  // Initially push the root node with state 1 (preorder)

        // While the stack is not empty
        while (!st.empty()) {
            auto it = st.top();  // Get the top node and its state
            st.pop();  // Remove it from the stack

            // If the state is 1, this is the part of preorder traversal
            if (it.second == 1) {
                pre.push_back(it.first->val);  // Add node value to preorder result
                it.second++;  // Increment state to 2 (inorder)
                st.push(it);  // Push it back with updated state

                // If the left child exists, push it with state 1 (preorder)
                if (it.first->left != nullptr) {
                    st.push({it.first->left, 1});
                }
            }
            // If the state is 2, this is the part of inorder traversal
            else if (it.second == 2) {
                in.push_back(it.first->val);  // Add node value to inorder result
                it.second++;  // Increment state to 3 (postorder)
                st.push(it);  // Push it back with updated state

                // If the right child exists, push it with state 1 (preorder)
                if (it.first->right != nullptr) {
                    st.push({it.first->right, 1});
                }
            }
            // If the state is 3, this is the part of postorder traversal
            else {
                post.push_back(it.first->val);  // Add node value to postorder result
            }
        }

        // Return all three traversal results
        return {pre, in, post};
    }
};



// RECURSIVE INORDER PREORDER POSTORDER TRAVERSAL 


class Solution {
public:
    // Function to perform recursive Preorder traversal (root, left, right)
    void recursivePreorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;  // Base case: if node is null, return
        result.push_back(root->val);  // Visit the root
        recursivePreorder(root->left, result);  // Traverse the left subtree
        recursivePreorder(root->right, result);  // Traverse the right subtree
    }

    // Function to perform recursive Inorder traversal (left, root, right)
    void recursiveInorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;  // Base case: if node is null, return
        recursiveInorder(root->left, result);  // Traverse the left subtree
        result.push_back(root->val);  // Visit the root
        recursiveInorder(root->right, result);  // Traverse the right subtree
    }

    // Function to perform recursive Postorder traversal (left, right, root)
    void recursivePostorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;  // Base case: if node is null, return
        recursivePostorder(root->left, result);  // Traverse the left subtree
        recursivePostorder(root->right, result);  // Traverse the right subtree
        result.push_back(root->val);  // Visit the root
    }
};




// 1)  TO FIND PATH FROM ROOT TO NODE OR NODE TO ROOT OF A BINARY TREE
 class Solution {
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
    
    private: vector<int> solve(TreeNode* A, int B) {
        vector<int> path;
        if (A == NULL) {
            return path;
        }
        
        getPath(A, path, B);
        return path;
    }
};




// 2) To find lowest common ancestor between any two nodes lca 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if (root == NULL || root == p || root == q) {
            return root;
        }

        // Search left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-null, root is the LCA
        if (left != NULL && right != NULL) {
            return root;
        }

        // Otherwise, return the non-null child (either left or right)
        return left != NULL ? left : right;
    }
};





// 3  FINDING ALL THE NODES AT A K DISTANCE FROM A TARGET NODE


class Solution {
public:
    // Helper function to mark parents of each node
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> queue;
        queue.push(root);
        parent_track[root] = nullptr;  // Root has no parent
        
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            
            if (current->left) {
                parent_track[current->left] = current;  // Mark the parent of the left child
                queue.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;  // Mark the parent of the right child
                queue.push(current->right);
            }
        }
    }

    // Function to find all nodes at distance k from the target node
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // Node -> Parent mapping
        markParents(root, parent_track);  // Mark all the parent nodes

        unordered_map<TreeNode*, bool> visited;  // To track visited nodes
        queue<TreeNode*> queue;  // For BFS
        queue.push(target);
        visited[target] = true;

        int curr_level = 0;  // Track the current level (distance from target)

        // Perform BFS to go up to K level from target node
        while (!queue.empty()) {
            int size = queue.size();
            if (curr_level == k) break;  // Stop when we reach the required distance

            for (int i = 0; i < size; i++) {
                TreeNode* current = queue.front();
                queue.pop();

                // Check the left child
                if (current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }

                // Check the right child
                if (current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }

                // Check the parent
                if (parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            curr_level++;  // Move to the next level
        }

        // Collect all nodes at distance K
        vector<int> result;
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }

        return result;
    }};

