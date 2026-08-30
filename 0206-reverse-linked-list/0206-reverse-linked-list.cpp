class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            // Save next node
            ListNode* next = curr->next;

            // Reverse the link
            curr->next = prev;

            // Move prev forward
            prev = curr;

            // Move curr forward
            curr = next;
        }

        // prev is the new head
        return prev;
    }
};