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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        //we need at least 2 nodes to swap
        while(prev->next!=NULL && prev->next->next!=NULL){
            ListNode* first=prev->next;
            ListNode* second=first->next;
            //save remaining lost
            ListNode* nextpair=second->next;
            //swap two nodes
            prev->next=second;
            second->next=first;
            first->next= nextpair;
            //move prev to end of swapped pair
            prev=first;
        }
        return dummy->next;
    }
};