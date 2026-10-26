class Solution {
public:
    vector<int> shortestAlternatingPaths(int n,vector<vector<int>>& redEdges,vector<vector<int>>& blueEdges) {
        vector<vector<int>> adj[2];
        adj[0].resize(n);
        adj[1].resize(n);
        for(auto &e:redEdges)adj[0][e[0]].push_back(e[1]);
        for(auto &e:blueEdges)adj[1][e[0]].push_back(e[1]);
        vector<vector<int>> dist(n,vector<int>(2,-1));
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        dist[0][0]=0;
        dist[0][1]=0;
        while(!q.empty()){
            auto [u,lastColor]=q.front();
            q.pop();
            int nextColor=1-lastColor;
            for(int v:adj[nextColor][u]){
                if(dist[v][nextColor]==-1){
                    dist[v][nextColor]=dist[u][lastColor]+1;
                    q.push({v,nextColor});
                }
            }
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(dist[i][0]==-1)ans[i]=dist[i][1];
            else if(dist[i][1]==-1)ans[i]=dist[i][0];
            else ans[i]=min(dist[i][0],dist[i][1]);
        }
        return ans;
    }
};