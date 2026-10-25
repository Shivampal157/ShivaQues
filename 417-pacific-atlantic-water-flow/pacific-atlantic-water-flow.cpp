class Solution {
public:
    int m,n;
    vector<vector<int>> pac,atl;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& heights,int i,int j,vector<vector<int>>& vis){
        vis[i][j]=1;
        for(auto &d:dir){
            int ni=i+d[0],nj=j+d[1];
            if(ni<0||nj<0||ni>=m||nj>=n||vis[ni][nj])continue;
            if(heights[ni][nj]>=heights[i][j]){
                dfs(heights,ni,nj,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        pac.assign(m,vector<int>(n,0));
        atl.assign(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dfs(heights,i,0,pac);
            dfs(heights,i,n-1,atl);
        }
        for(int j=0;j<n;j++){
            dfs(heights,0,j,pac);
            dfs(heights,m-1,j,atl);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j]&&atl[i][j])ans.push_back({i,j});
            }
        }
        return ans;
    }
};