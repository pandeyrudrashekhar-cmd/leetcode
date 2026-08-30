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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        //move fast n+1
        for(int i=0; i<=n; i++){
            fast=fast->next;
        }
        //move both pointer
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        //remove nth node
        slow->next=slow->next->next;
        return dummy->next;
    }
};