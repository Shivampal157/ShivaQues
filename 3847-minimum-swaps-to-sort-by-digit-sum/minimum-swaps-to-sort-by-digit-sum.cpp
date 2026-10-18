class Solution {
public:
    int digitSum(int x){
        int sum=0;
        while(x>0){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums){
        int n=nums.size();
        vector<array<int,3>> a;

        for(int i=0;i<n;i++){
            a.push_back({digitSum(nums[i]),nums[i],i});
        }

        sort(a.begin(),a.end());

        vector<bool> vis(n,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(vis[i]||a[i][2]==i) continue;

            int j=i;
            int cycle=0;

            while(!vis[j]){
                vis[j]=true;
                j=a[j][2];
                cycle++;
            }

            ans+=cycle-1;
        }

        return ans;
    }
};