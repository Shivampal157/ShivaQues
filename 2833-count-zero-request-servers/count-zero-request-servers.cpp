class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int k=queries.size(),m=logs.size();
        vector<int> ans(k);
        vector<pair<int,int>> q(k);
        for(int i=0;i<k;i++) q[i]={queries[i],i};
        sort(q.begin(),q.end());
        sort(logs.begin(),logs.end(),[](auto& a,auto& b){
            return a[1]<b[1];
        });
        vector<int> c(n+1,0);
        int act=0,l=0,r=0;
        for(auto& p: q){
            int cur=p.first,idx=p.second;
            while(r<m&&logs[r][1]<=cur){
                if(c[logs[r][0]]++==0) act++;
                r++;
            }
            while(l<m&&logs[l][1]<cur-x){
                if(--c[logs[l][0]]==0) act--;
                l++;
            }
            ans[idx]=n-act;
        }
        return ans;
    }
};