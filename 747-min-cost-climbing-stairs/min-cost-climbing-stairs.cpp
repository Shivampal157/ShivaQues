class Solution {
public:
    int t[1001];
    int solve(vector<int>& cost,int i){
        if(i<0) return 0;
        if(i==0) return cost[0];
        if(i==1) return cost[1];
        if(t[i]!=-1) return t[i];
        return t[i]=cost[i]+min(solve(cost,i-1),solve(cost,i-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        memset(t,-1,sizeof(t));
        return min(solve(cost,n-1),solve(cost,n-2));
        
    }
};