class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) adj[parent[i]].push_back(i);
        vector<int> ans(n, 1), lastSeen(26, -1);
        auto dfs = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev = lastSeen[c];
            lastSeen[c] = u;
            for (int v : adj[u]) self(self, v);
            lastSeen[c] = prev;
            int newParent = (prev != -1) ? prev : parent[u];
            if (newParent != -1) ans[newParent] += ans[u];
        };
        dfs(dfs, 0);
        return ans;
    }
};