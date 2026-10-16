class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* curr=head;
        vector<int>v;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr=curr->next;
        }
        int res=0;
        int i=0;
        int j=v.size()-1;
        while(i<j){
            res=max(res,v[i]+v[j]);
            i++;
            j--;
        }

        return res;
    }
};