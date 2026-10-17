class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;
        // Path compression
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        // Union by Rank
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } 
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } 
        else {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // If there are fewer edges than n-1, it's impossible to connect all nodes
        if(connections.size() < n - 1)
            return -1;

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        int components = n; // Initially, every node is its own component (ilaka)

        for(auto &vec : connections) {
            // If the two nodes belong to different components, union them
            if(find(vec[0]) != find(vec[1])) {
                Union(vec[0], vec[1]);
                components--; // Connecting two components reduces the total number of components by 1
            }
        }

        // To connect 'C' components, we need 'C - 1' edges (operations)
        return components - 1;
    }
};