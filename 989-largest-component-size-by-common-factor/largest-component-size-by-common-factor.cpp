class Solution{
public:
    vector<int>parent,sz;

    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b)return;

        if(sz[a]<sz[b])swap(a,b);

        parent[b]=a;
        sz[a]+=sz[b];
    }

    int largestComponentSize(vector<int>&nums){
        int n=nums.size();
        parent.resize(n);
        sz.assign(n,1);

        for(int i=0;i<n;i++)parent[i]=i;

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            int x=nums[i];

            for(int p=2;p*p<=x;p++){
                if(x%p==0){
                    if(mp.count(p))
                        unite(i,mp[p]);
                    else
                        mp[p]=i;

                    while(x%p==0)x/=p;
                }
            }

            if(x>1){
                if(mp.count(x))
                    unite(i,mp[x]);
                else
                    mp[x]=i;
            }
        }

        int ans=0;

        for(int i=0;i<n;i++)
            ans=max(ans,sz[find(i)]);

        return ans;
    }
};