
// GRAPHS GRAPH GRAPHS GRAPH GRAPH GRAPH GRAPH GRAPH GRAPHS GRAPH

#include <bits/stdc++.h>
using namespace std;


// Storing the graph
class GraphStorage {
public:
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
    }
};

// BFS (Breadth-First Search)
class BFS {
public:
    // Function to return Breadth First Traversal of the given graph
    vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> bfs;              // To store the BFS traversal
        vector<int> vis(V, 0);        // Visited array
        queue<int> q;

        q.push(0);                    // Assuming BFS starts from treenode 0
        vis[0] = 1;

        while(!q.empty()) {
            int treenode = q.front();
            q.pop();
            bfs.push_back(treenode);

            // Traverse all its neighbors
            for(auto it : adj[treenode]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

// DFS (Depth-First Search)
class DFS {
public:
    // Helper function for DFS traversal
    void dfs(int treenode, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res) {
        vis[treenode] = 1;
        res.push_back(treenode);

        // Traverse all its neighbors
        for(auto it : adj[treenode]) {
            if(!vis[it]) {
                dfs(it, adj, vis, res);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph
    vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> res;              // To store the DFS traversal
        vector<int> vis(V, 0);        // Visited array

        // Assuming DFS starts from treenode 0
        dfs(0, adj, vis, res);

        return res;
    }
};

// Number of connected components using BFS
class NumIslandsBFS {
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
};

// Flood Fill Algorithm using DFS
class FloodFillDFS {
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
};

// Time taken to rot all oranges
class RottenOranges {
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
        int delRow[] = {-1, 0, 1, 0};  // Direction arrays for 4 directions
        int delCol[] = {0, 1, 0, -1};

        // Perform BFS for rotting process
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;  // Current time
            time = max(time, t);
            q.pop();

            // Traverse all 4 neighboring cells
            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                // Check if the neighboring cell is within bounds and contains a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    q.push({{nrow, ncol}, t + 1});  // Add the fresh orange to the queue with incremented time
                    vis[nrow][ncol] = 1;           // Mark the orange as visited
                    grid[nrow][ncol] = 2;          // Update the orange to rotten
                }
            }
        }

        // Check if any fresh orange remains
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;  // Return -1 if there is any fresh orange left
            }
        }

        return time;  // Return the minimum time required
    }
};

// Shortest Path in an Undirected Graph
class ShortestPath {
public:
    // Function to find the shortest path in an unweighted undirected graph
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<int> adj[N];  // Adjacency list representation of the graph
        
        // Create the adjacency list from the edges
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }

        // Array to store the shortest distance from source (0) to each node
        vector<int> dist(N, 1e9);
        dist[0] = 0;  // Distance of source to itself is 0
        
        // BFS for shortest path
        queue<int> q;
        q.push(0);  // Start BFS from node 0

        while (!q.empty()) {
            int treenode = q.front();
            q.pop();

            // Traverse all its neighbors
            for (auto it : adj[treenode]) {
                if (dist[treenode] + 1 < dist[it]) {
                    dist[it] = dist[treenode] + 1;  // Update the shortest distance
                    q.push(it);                    // Push the neighbor to the queue
                }
            }
        }

        // Replace unreachable distances with -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;  // Return the shortest distances array
    }
};

int main() {
    // Example usage for each class can be inserted here for testing
    return 0;
}
