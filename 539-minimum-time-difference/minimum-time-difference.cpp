class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for(string s:timePoints){
            int h=stoi(s.substr(0,2));
            int m=stoi(s.substr(3,2));
            v.push_back(h*60+m);
        }
        sort(v.begin(),v.end());
        int ans=1440;
        for(int i=1;i<v.size();i++){
            ans=min(ans,v[i]-v[i-1]);
        }
        ans=min(ans,1440-v.back()+v[0]);
        return ans;
    }
};