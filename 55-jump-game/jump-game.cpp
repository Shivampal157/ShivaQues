class Solution {
public:
    bool canJump(vector<int>& nums) {
       int fart=0;
       for(int i=0;i<nums.size();i++){
        if(i>fart) return false;
        fart=max(fart,i+nums[i]);
       }
       return true;
        
    }
};