class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        if(n==0) return 0;
        int arrow=1;
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
           
            int ns=intervals[i][0];
            int ne=intervals[i][1];
            if(ns>end){
               
                arrow++;
                end=ne;

            }
           else{
            end=min(end,ne);
                
            }
        }
        return arrow;
        
    }
};