class Solution{
public:
    long long minSumSquareDiff(vector<int>&nums1,vector<int>&nums2,int k1,int k2){
        int n=nums1.size();
        long long k=(long long)k1+k2;
        vector<long long>d(n);
        long long sum=0,mx=0;

        for(int i=0;i<n;i++){
            d[i]=abs(nums1[i]-nums2[i]);
            sum+=d[i];
            mx=max(mx,d[i]);
        }

        if(sum<=k)return 0;

        long long low=0,high=mx;

        while(low<high){
            long long mid=low+(high-low)/2;
            long long need=0;

            for(long long x:d){
                if(x>mid)need+=x-mid;
            }

            if(need<=k)high=mid;
            else low=mid+1;
        }

        long long ans=0,used=0;

        for(long long x:d){
            if(x>low){
                used+=x-low;
                x=low;
            }
            ans+=x*x;
        }

        long long remaining=k-used;

        for(long long i=0;i<n&&remaining>0;i++){
            if(d[i]>=low&&d[i]>0){
                ans-=low*low;
                ans+=(low-1)*(low-1);
                remaining--;
            }
        }

        return ans;
    }
};