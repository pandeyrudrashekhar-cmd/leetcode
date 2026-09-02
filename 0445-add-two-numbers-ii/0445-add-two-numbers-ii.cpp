class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1;
        stack<int> s2;

        // Put first number into stack
        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Put second number into stack
        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;

        // Result list starts empty
        ListNode* head = NULL;

        // Add from right to left
        while (!s1.empty() || !s2.empty() || carry != 0) {

            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            int digit = sum % 10;
            carry = sum / 10;

            // Insert digit at the front
            ListNode* newNode = new ListNode(digit);

            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};