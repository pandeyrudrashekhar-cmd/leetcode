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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        //step 1:- find length
        int n=1;
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
            n++;
        }
        //remove unnecessary rotation
        k=k%n;

        if(k==0){
            //no rotation needed
            return head;
        }
        //make list circular
        tail->next=head;

        //find new tail:- new tail will be at position n-k. so move till there
        ListNode* newTail=head;
        for(int i=1; i<n-k; i++){
            newTail=newTail->next;
        }
        //new head find
        ListNode* NewHead=newTail->next;
        //break the circular list
        newTail->next=NULL;
        return NewHead;

    }
};