//                    TREE  


// ITERATIVE LEVEL ORDER TRAVERSAL BFS OF A BINARY TREE

/*
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
};*/





// ITERATIVE PREORDER POSTORDER INORDER IN A SINGLE GO 

/*
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
};*/




// RECURSIVE INORDER PREORDER POSTORDER TRAVERSAL 

/*
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
};*/





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




// 2) To find lowest common ancestor between any two nodes lca 

/*
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
*/




// 3  FINDING ALL THE NODES AT A K DISTANCE FROM A TARGET NODE

/*
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
*/








//                    BST BST BST BST BST BST BST BST BST 



//                 SEARCH IN BST
/*
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
*/


//  CEIL AND FLOOR IN BST 

/*
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
*/



// INSERT A NODE IN BST

/*
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
    }*/



   // DELETE A  NODE IN BST

   /*
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
};*/





// CHECK IF THE GIVEN BST IS A VALID BST

/*
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
};*/



// TO FIND LCA OF BST 

/*
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
        return root;  // Current node is the LCA*/


















//  GRAPHS GRAPH GRAPHS GRAPH GRAPH GRAPH GRAPH GRAPH GRAPHS GRAPH



// storing the graph 

/*
// Function to store the graph as a matrix
void storeAsMatrix(int n, int m) {
    vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, 0));  // Initialize an n+1 x n+1 matrix

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // Assuming an undirected graph
    }

    // Display adjacency matrix (optional)
    cout << "Adjacency Matrix:" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to store the graph as an adjacency list
void storeAsAdjList(int n, int m) {
    vector<vector<int>> adjList(n+1);  // Initialize an adjacency list

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Assuming an undirected graph
    }

    // Display adjacency list (optional)
    cout << "Adjacency List:" << endl;
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(auto v : adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}*/







// BFS BFS  BREADTH FIRST SEARCH BFS BFS BFS BFS

/*
 // Function to return Breadth First Traversal of the given graph
    vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> bfs;              // To store the BFS traversal
        vector<int> vis(V, 0);        // Visited array
        queue<int> q;

        q.push(0);                    // Assuming BFS starts from node 0
        vis[0] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            // Traverse all its neighbors
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }

    
*/







// DFS DFS DFS DFS DFS DEPTH FIRST SEARCH

/*
// Helper function for DFS traversal
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res) {
        vis[node] = 1;
        res.push_back(node);

        // Traverse all its neighbors
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, res);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph
    vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> res;              // To store the DFS traversal
        vector<int> vis(V, 0);        // Visited array

        // Assuming DFS starts from node 0
        int ct=0;
        for (int i=0;i<V;i++){
        if(!vis[i]){
        dfs(i,adj,vis,res);
        ct++;
        }
        }
        dfs(0, adj, vis, res);

        return res;
    }


*/



// Number of connected components using BFS

/*
class Solution {
public:
    // Function to perform BFS and mark visited cells
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Queue for BFS traversal
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        // Direction vectors for 4-connected neighbors
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while(!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();

            // Traverse all its 4-connected neighbors
            for(int i = 0; i < 4; i++) {
                int nRow = curRow + dRow[i];
                int nCol = curCol + dCol[i];

                // Check bounds and if the cell is a land ('1') and not visited
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                    && grid[nRow][nCol] == '1' && !vis[nRow][nCol]) {
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }
    }

    // Function to find the number of islands (connected components of '1's)
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));  // Visited array
        int cnt = 0;

        // Traverse the grid to find unvisited land cells
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(grid[row][col] == '1' && !vis[row][col]) {
                    cnt++;  // Found a new island
                    bfs(row, col, vis, grid);  // Mark the whole island
                }
            }
        }
        return cnt;  // Return the number of islands
    }
};*/




// FLOOD FILL ALGORITHM USING DFS

/*
class Solution {
private:
    // Helper function to perform DFS
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, vector<int>& delRow, vector<int>& delCol, int iniColor) {
        ans[row][col] = newColor;  // Change color
        int n = image.size();
        int m = image[0].size();

        // Traverse in all 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Check boundaries and ensure the next cell has the initial color and is not yet colored
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
            }
        }
    }

public:
    // Main function to perform flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];  // Initial color of the starting cell
        vector<vector<int>> ans = image;  // Result image

        // If the initial color is already the new color, no need to proceed
        if (iniColor == newColor) return ans;

        // Direction vectors for up, down, left, right
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Call DFS to start flood fill from the starting cell (sr, sc)
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);

        return ans;
    }
};*/



// Time taken to rot all oranges

/*class Solution {
public:
    // Function to find the minimum time required to rot all oranges
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();            // Number of rows
        int m = grid[0].size();         // Number of columns
        queue<pair<pair<int, int>, int>> q;  // Queue to store {{row, col}, time}
        vector<vector<int>> vis(n, vector<int>(m, 0));  // Visited array
        
        // Add all initially rotten oranges to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});  // Rotten orange at time 0
                    vis[i][j] = 1;        // Mark as visited
                }
            }
        }

        int time = 0;  // To store the minimum time required
        int delRow[] = {-1, 0, 1, 0};  // Direction arrays for row (up, right, down, left)
        int delCol[] = {0, 1, 0, -1};  // Direction arrays for column

        // BFS to rot the adjacent fresh oranges
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);  // Update the maximum time

            // Traverse all 4 adjacent cells
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                // Check if the cell is within bounds and is a fresh orange
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && !vis[nRow][nCol]) {
                    q.push({{nRow, nCol}, t + 1});  // Mark as rotten and add to queue
                    vis[nRow][nCol] = 1;  // Mark as visited
                    grid[nRow][nCol] = 2;  // Mark the orange as rotten in the grid
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;  // If any fresh orange remains, return -1
                }
            }
        }

        return time;  // Return the minimum time required to rot all oranges
    }
};
*/