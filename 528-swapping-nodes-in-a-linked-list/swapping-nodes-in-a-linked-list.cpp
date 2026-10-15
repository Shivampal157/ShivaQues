class Solution {
public:
      int findL(ListNode* head){
        int l=0;
        while(head){
            head=head->next;
            l++;
        }
        return l;

      }
    ListNode* swapNodes(ListNode* head, int k) {
        int l=findL(head);
        int k1=k;
         ListNode* node1=head;
         while(k1>1){
            node1=node1->next;
            k1--;
         }
          int k2=l-k+1;
         ListNode* node2=head;
         while(k2>1){
            node2=node2->next;
            k2--;
         }

        swap(node1->val,node2->val);
        return head;
    }
};