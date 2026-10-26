class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int gap=0;
        for(int i=1;i<n;i++){
           
                
                 gap=max(gap,nums[i]-nums[i-1]);

            
            
        }
        return gap;
        
    }
};