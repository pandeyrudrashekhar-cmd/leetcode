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
    bool isPalindrome(ListNode* head) {
        //if linkedlist has zero or one element then it will always be true;
        if(head==NULL || head->next==NULL) return true;
        //find middle
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //now slow is head of middle part
        //reverse second half
        ListNode* prev=NULL;
        ListNode* curr=slow;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        //compare both half
       //prev is now head of reverse LL
       ListNode* a=head;
       ListNode* b=prev;
       while(b){
        if(a->val!=b->val){
            return false;
        }
        a=a->next;
        b=b->next;
       }
       return true;
    }
};