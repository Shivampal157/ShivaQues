class Solution{
public:
    int sortPermutation(vector<int>&nums){
        int n=nums.size(),ans=-1;
        bool sorted=true;

        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                sorted=false;
                if(ans==-1)ans=nums[i]&i;
                else ans&=nums[i]&i;
            }
        }

        return sorted?0:ans;
    }
};