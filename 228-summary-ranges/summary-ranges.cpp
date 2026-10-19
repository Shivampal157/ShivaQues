class Solution{
public:
    vector<string>summaryRanges(vector<int>&nums){
        vector<string>ans;
        int n=nums.size(),i=0;

        while(i<n){
            int start=nums[i];

            while(i+1<n&&(long long)nums[i+1]==(long long)nums[i]+1){
                i++;
            }

            if(start!=nums[i]){
                ans.push_back(to_string(start)+"->"+to_string(nums[i]));
            }
            else{
                ans.push_back(to_string(start));
            }

            i++;
        }

        return ans;
    }
};