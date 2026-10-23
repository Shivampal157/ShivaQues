class Solution{
public:
    int minimumTeachings(int n,vector<vector<int>>&languages,vector<vector<int>>&friendships){
        int m=languages.size();
        vector<unordered_set<int>>known(m+1);

        for(int i=1;i<=m;i++){
            for(int lang:languages[i-1])
                known[i].insert(lang);
        }

        unordered_set<int>need;

        for(auto&f:friendships){
            int u=f[0],v=f[1];
            bool common=false;

            for(int lang:known[u]){
                if(known[v].count(lang)){
                    common=true;
                    break;
                }
            }

            if(!common){
                need.insert(u);
                need.insert(v);
            }
        }

        if(need.empty())return 0;

        int ans=INT_MAX;

        for(int lang=1;lang<=n;lang++){
            int teach=0;

            for(int person:need){
                if(!known[person].count(lang))
                    teach++;
            }

            ans=min(ans,teach);
        }

        return ans;
    }
};