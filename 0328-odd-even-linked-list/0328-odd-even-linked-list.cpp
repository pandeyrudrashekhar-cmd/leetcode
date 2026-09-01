class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=even;
        while(even!=NULL && even->next!=NULL){
            //connect odd node to next odd node
            odd->next=even->next;
            odd=odd->next;
            //connect even node to next even node
            even->next=odd->next;
            even=even->next;
        }
            //attach even list after off list
            odd->next=evenHead;
            return head;
        
    }
};