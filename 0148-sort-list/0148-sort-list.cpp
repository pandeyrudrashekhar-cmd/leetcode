/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* merge(ListNode* L1, ListNode* L2){
    ListNode* dummy=new ListNode(0);
    ListNode* curr=dummy;
    //compare node from both nodes
    while(L1!=NULL && L2!=NULL){
        if(L1->val<L2->val){
            curr->next=L1;
            L1=L1->next;
        }
        else{
            curr->next=L2;
            L2=L2->next;
        }
        curr=curr->next;
    }
    //if something is still left
    if(L1){
        curr->next=L1;
    }
    else{
        curr->next=L2;
    }
    return dummy->next;
}

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        //find middle
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //sec half starts after slow
        ListNode* second=slow->next;
        //break the list
        slow->next=NULL;
        //try to recursively sort both half
        ListNode* left=sortList(head);
        ListNode* right=sortList(second);

        return merge(left,right);

    }
};