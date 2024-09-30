//                    BST BST BST BST BST BST BST BST BST 
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int x) {
        val = x;
        right = NULL;
        left = NULL;
    }
};


//                 SEARCH IN BST

TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            // If value is smaller, search the left subtree
            if (val < root->val) {
                root = root->left;
            } 
            // If value is greater, search the right subtree
            else {
                root = root->right;
            }
        }
        return root;  // Will be nullptr if not found
    }


//  CEIL AND FLOOR IN BST 


 int findCeil(TreeNode* root, int key) {
        int ceil = -1;  // Initialize the ceil value to -1 (if no ceil exists)
        while (root != nullptr) {
            if (root->val == key) {
                return root->val;  // If the key matches, return the node's value as the ceil
            }
            if (key < root->val) {
                // Move to the left, but store the current node's value as a potential ceil
                ceil = root->val;
                root = root->left;
            } else {
                // Move to the right as the current node's value is smaller than the key
                root = root->right;
            }
        }
        return ceil;  // Return the ceil value found
    }



// INSERT A NODE IN BST


TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);  // If the tree is empty, create a new node

        TreeNode* cur = root;
        while (true) {
            if (val < cur->val) {
                // Move to the left subtree
                if (cur->left == nullptr) {
                    cur->left = new TreeNode(val);  // Insert the new node
                    break;
                } else {
                    cur = cur->left;
                }
            } else {
                // Move to the right subtree
                if (cur->right == nullptr) {
                    cur->right = new TreeNode(val);  // Insert the new node
                    break;
                } else {
                    cur = cur->right;
                }
            }
        }
        return root;  // Return the root of the modified tree
    }



   // DELETE A  NODE IN BST

   
   class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;  // If the tree is empty, return nullptr

        if (key < root->val) {
            root->left = deleteNode(root->left, key);  // Recursively delete from the left subtree
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);  // Recursively delete from the right subtree
        } else {
            // Node found: handle 3 cases (0, 1, 2 children)
            if (root->left == nullptr) {
                // Node has no left child, replace node with the right child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                // Node has no right child, replace node with the left child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node has two children: find the inorder successor (smallest in the right subtree)
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;  // Copy the inorder successor's value to the current node
            root->right = deleteNode(root->right, temp->val);  // Delete the inorder successor
        }
        return root;
    }

private:
    // Helper function to find the minimum value node in the BST (inorder successor)
    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) root = root->left;  // The leftmost node is the minimum
        return root;
    }
};





// CHECK IF THE GIVEN BST IS A VALID BST


class Solution {
public:
    // Function to check if the tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // Start with the minimum and maximum possible values
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

private:
    // Helper function to validate the BST
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        // An empty tree is a valid BST
        if (root == nullptr) return true;

        // If the current node's value is not within the valid range, return false
        if (root->val <= minVal || root->val >= maxVal) return false;

        // Recursively check the left subtree (all values must be less than the current node's value)
        // and the right subtree (all values must be greater than the current node's value)
        return isValidBST(root->left, minVal, root->val) && 
               isValidBST(root->right, root->val, maxVal);
    }
};



// TO FIND LCA OF BST 


 // Function to find the Lowest Common Ancestor of two nodes p and q in a BST
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If root is null, return null
        if (root == nullptr) return nullptr;

        int curr = root->val;  // Store the current node's value

        // If both p and q are greater than current node, search in the right subtree
        if (curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // If both p and q are smaller than current node, search in the left subtree
        if (curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If p and q are on either side of the current node or one of them is the current node
        return root;  // Current node is the LCA

