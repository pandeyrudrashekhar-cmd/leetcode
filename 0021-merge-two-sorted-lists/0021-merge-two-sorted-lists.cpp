class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node helps us easily build the result list
        ListNode* dummy = new ListNode(-1);

        // tail points to the last node of our result list
        ListNode* tail = dummy;

        // Compare nodes while both lists have elements
        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {

                // Take node from list1
                tail->next = list1;
                list1 = list1->next;

            } else {

                // Take node from list2
                tail->next = list2;
                list2 = list2->next;
            }

            // Move tail forward
            tail = tail->next;
        }

        // Attach whichever list is still remaining
        if (list1 != NULL) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Dummy itself is not part of the answer
        return dummy->next;
    }
};