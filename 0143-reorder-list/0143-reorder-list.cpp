class Solution {
public:
    void reorderList(ListNode* head) {

        // If there are 0 or 1 nodes
        if (head == NULL || head->next == NULL)
            return;

        // -----------------------------
        // STEP 1: Find the middle
        // -----------------------------

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is at the middle
        // Example: 1 -> 2 -> 3 -> 4 -> 5
        //                    slow
        

        // -----------------------------
        // STEP 2: Reverse second half
        // -----------------------------

        ListNode* second = slow->next;

        // Break the list into two parts
        slow->next = NULL;

        ListNode* prev = NULL;

        while (second != NULL) {

            ListNode* nextNode = second->next;

            second->next = prev;

            prev = second;
            second = nextNode;
        }

        // prev is the head of reversed second half


        // -----------------------------
        // STEP 3: Merge both halves
        // -----------------------------

        ListNode* first = head;
        second = prev;

        while (second != NULL) {

            // Save next nodes
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            // Connect first -> second
            first->next = second;

            // Connect second -> next first
            second->next = firstNext;

            // Move forward
            first = firstNext;
            second = secondNext;
        }
    }
};