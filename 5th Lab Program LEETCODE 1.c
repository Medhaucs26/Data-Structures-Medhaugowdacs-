/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *slow, *fast;
    slow = head;
    fast = head->next;

    while (fast != NULL) {
        if (slow->val == fast->val) {
            slow->next = fast->next;
            fast = fast->next;
        } else {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return head;
}
