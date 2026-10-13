class Solution{
public:

    TreeNode*sortedListToBST(ListNode*head){
         if(!head)return NULL;
        if(!head->next)return new TreeNode(head->val);

        ListNode*prev=NULL;
        ListNode*slow=head;
        ListNode*fast=head;

        while(fast&&fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        prev->next=NULL;
        TreeNode* root=new TreeNode(slow->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        return root;
    }
};