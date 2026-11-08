class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size(),m=tasks.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> free;
        for(int i=0;i<n;i++) free.push({servers[i],i});
        priority_queue<array<long long,3>,vector<array<long long,3>>,greater<array<long long,3>>> busy;
        vector<int> ans(m);
        long long cur=0;
        for(int i=0;i<m;i++){
            cur=max(cur,1LL*i);
            if(free.empty()&&!busy.empty()) cur=max(cur,busy.top()[0]);
            while(!busy.empty()&&busy.top()[0]<=cur){
                free.push({(int)busy.top()[1],(int)busy.top()[2]});
                busy.pop();
            }
            auto s=free.top();
            free.pop();
            ans[i]=s.second;
            busy.push({cur+tasks[i],s.first,s.second});
        }
        return ans;
    }
};