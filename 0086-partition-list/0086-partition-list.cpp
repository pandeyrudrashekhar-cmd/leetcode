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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallhead=new ListNode(0);
        ListNode* bighead=new ListNode(0);

        ListNode* small=smallhead;
        ListNode* big=bighead;
        //traverse
        while(head){
            if(head->val<x){
                small->next=head;
                small=small->next;
            }
            else{
                big->next=head;
                big=big->next;
            }
            head=head->next;
        }
        //end the lig list
        big->next=NULL;
        small->next=bighead->next;
        return smallhead->next;
    }
};