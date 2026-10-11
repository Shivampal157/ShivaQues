class Solution {
public:
   bool dfs(vector<vector<int>>& graph,int curr,vector<int>&color,int currC){
    color[curr]=currC;
    for(int &v:graph[curr]){
        if(color[v]==color[curr]){
            return false;
        }
        if(color[v]==-1){
            int colorOfV=1-currC;
        
        if(dfs(graph,v,color,colorOfV)==false){
            return false;
        }
        }
    }
    return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
               if(dfs(graph,i,color,1)==false){

                return false;
               }
            }
        }
        return true;
        
    }
};