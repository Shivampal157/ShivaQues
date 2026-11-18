class Solution {
public:
        int findBound(vector<int>& nums, int target, bool findFirst) {
        int l = 0, r = (int)nums.size() - 1;
        int bound = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                bound = mid; // Jeb me save kar lo!
                if (findFirst) {
                    r = mid - 1; // Leftmost ke liye Left me talash jari rakho
                } else {
                    l = mid + 1; // Rightmost ke liye Right me talash jari rakho
                }
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return bound;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
         int first = findBound(nums, target, true);
        if (first == -1) return {-1, -1}; // Agar first hi nahi mila toh target array me hai hi nahi!
        int last = findBound(nums, target, false);
        return {first, last};
        
    }
};