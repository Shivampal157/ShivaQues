class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        if(l1->val<l2->val){
            l1->next= mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next= mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
    ListNode* partitionMerge(int st,int end,vector<ListNode*>&lists){
         if(st>end){
            return NULL;
        }
        if(st==end) return lists[st];
        int mid=st+(end-st)/2;
       ListNode*  L1= partitionMerge(st,mid,lists);
       ListNode*  L2= partitionMerge(mid+1,end,lists);
       return mergeTwoLists(L1,L2);

       

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        return partitionMerge(0,k-1,lists);
          
        
    }
};