class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        int cnt=0;
        int i=0;
        int j=1;
        while(j<n){
            vector<int>curr_int=intervals[i];
            vector<int>next_int=intervals[j];
            int cs=curr_int[0];
            int ce=curr_int[1];
            int ns=next_int[0];
            int ne=next_int[1];
            if(ce<=ns){//no overlapping
                i=j;
                j++;
                


            }
           else if(ce<=ne){
            j++;
            cnt++;

            }else if(ce>ne){
                i=j;
                j++;
                cnt++;
            }
        }
        return cnt;
            
    }
};