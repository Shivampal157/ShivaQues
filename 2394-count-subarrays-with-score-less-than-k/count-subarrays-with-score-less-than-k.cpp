class Solution{
public:
    long long countSubarrays(vector<int>&nums,long long k){
        int n=nums.size(),l=0;
        long long sum=0,ans=0;

        for(int r=0;r<n;r++){
            sum+=nums[r];

            while(l<=r&&sum*(r-l+1)>=k){
                sum-=nums[l];
                l++;
            }

            ans+=r-l+1;
        }

        return ans;
    }
};