class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                
                if(n%nums[j]==0 &&j==i){
                  cnt++;
                   

                }
            }
            if(n%(i+1)==0){
                ans+=nums[i]*nums[i];
            }
        }
        return ans;
        
    }
};