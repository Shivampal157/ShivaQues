class Solution{
public:
    vector<int>get(vector<int>&a,int k){
        int drop=a.size()-k;
        vector<int>st;

        for(int x:a){
            while(!st.empty()&&drop&&st.back()<x){
                st.pop_back();
                drop--;
            }
            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    bool greaterVec(vector<int>&a,int i,vector<int>&b,int j){
        while(i<a.size()&&j<b.size()&&a[i]==b[j]){
            i++;
            j++;
        }
        return j==b.size()||(i<a.size()&&a[i]>b[j]);
    }

    vector<int>merge(vector<int>&a,vector<int>&b){
        vector<int>ans;
        int i=0,j=0;

        while(i<a.size()||j<b.size()){
            if(greaterVec(a,i,b,j))
                ans.push_back(a[i++]);
            else
                ans.push_back(b[j++]);
        }

        return ans;
    }

    vector<int>maxNumber(vector<int>&nums1,vector<int>&nums2,int k){
        vector<int>ans;

        int l=max(0,k-(int)nums2.size());
        int r=min(k,(int)nums1.size());

        for(int i=l;i<=r;i++){
            vector<int>a=get(nums1,i);
            vector<int>b=get(nums2,k-i);
            vector<int>cur=merge(a,b);

            if(ans.empty()||greaterVec(cur,0,ans,0))
                ans=cur;
        }

        return ans;
    }
};