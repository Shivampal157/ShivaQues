class Solution {
public:
    typedef pair<int, int> P;
    
    // The missing helper function to run Prim's Algorithm
    int PrimsAlgo(vector<vector<P>>& adj, int V) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0}); // {weight, node}
        
        vector<bool> inMST(V, false);
        int sum = 0;
        
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            // If the node is already in the MST, skip it
            if (inMST[node] == true) {
                continue;
            }
            
            inMST[node] = true;
            sum += wt;
            
            // Traverse adjacent nodes
            for (auto& tmp : adj[node]) {
                int neighbor = tmp.first;  // Note: using .first because adj stores pair<int, int>
                int neighbor_wt = tmp.second;
                
                if (inMST[neighbor] == false) {
                    pq.push({neighbor_wt, neighbor});
                }
            }
        }
        
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        
        // Adjacency list storing {neighbor, weight}
        vector<vector<P>> adj(V);
        
        // Build the graph by calculating the Manhattan distance between all pairs
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                // Manhattan distance formula
                int d = abs(x1 - x2) + abs(y1 - y2);
                
                // Undirected graph, so push both ways
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }
        
        // Call Prim's Algorithm to find the Minimum Spanning Tree
        return PrimsAlgo(adj, V);
    }
};