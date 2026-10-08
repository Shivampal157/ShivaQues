class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jump=0;
        int currentEnd=0;
        int fart=0;

        for(int i=0;i<n-1;i++){
            fart=max(fart,i+nums[i]);
            if(i==currentEnd){
                jump++;
                currentEnd=fart;
            }

        }
        return jump;
        
    }
};