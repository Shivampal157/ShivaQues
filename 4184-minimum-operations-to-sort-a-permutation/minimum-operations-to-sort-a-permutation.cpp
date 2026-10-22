class Solution{
public:
    int minOperations(vector<int>&nums){
        int n=nums.size(),pos0=0,posLast=0;
        bool inc=true,dec=true;

        for(int i=0;i<n;i++){
            if(nums[i]==0)pos0=i;
            if(nums[i]==n-1)posLast=i;

            int next=nums[(i+1)%n];

            if(next!=(nums[i]+1)%n)inc=false;
            if(next!=(nums[i]-1+n)%n)dec=false;
        }

        int ans=INT_MAX;

        if(inc)
            ans=min(ans,min(pos0,n-pos0+2));

        if(dec)
            ans=min(ans,min(n-pos0,posLast+1));

        return ans==INT_MAX?-1:ans;
    }
};