class Solution {
public:
    int timer=0;
    vector<int> tin,low;
    vector<vector<int>> ans;
    void dfs(int u,int parent,vector<vector<int>>& adj){
        tin[u]=low[u]=timer++;
        for(int v:adj[u]){
            if(v==parent)continue;
            if(tin[v]!=-1){
                low[u]=min(low[u],tin[v]);
            }else{
                dfs(v,u,adj);
                low[u]=min(low[u],low[v]);
                if(low[v]>tin[u]){
                    ans.push_back({u,v});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        tin.assign(n,-1);
        low.assign(n,-1);
        for(int i=0;i<n;i++){
            if(tin[i]==-1)dfs(i,-1,adj);
        }
        return ans;
    }
};