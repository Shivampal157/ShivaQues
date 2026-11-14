class Solution{
public:
    bool containsNearbyAlmostDuplicate(vector<int>&nums,int indexDiff,int valueDiff){
        multiset<long long>s;
        int n=nums.size();

        for(int i=0;i<n;i++){
            long long x=nums[i];

            auto it=s.lower_bound(x-valueDiff);

            if(it!=s.end()&&*it<=x+valueDiff){
                return true;
            }

            s.insert(x);

            if(s.size()>indexDiff){
                s.erase(s.find(nums[i-indexDiff]));
            }
        }

        return false;
    }
};