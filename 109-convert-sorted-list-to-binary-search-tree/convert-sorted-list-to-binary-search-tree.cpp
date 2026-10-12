class Solution{
public:
    TreeNode*solve(ListNode*head){
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

        TreeNode*root=new TreeNode(slow->val);
        root->left=solve(head);
        root->right=solve(slow->next);

        return root;
    }

    TreeNode*sortedListToBST(ListNode*head){
        return solve(head);
    }
};