
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *temp, *prev;

    while (head != NULL && head->val == val) {
        temp = head;
        head = head->next;
        free(temp);
    }
    temp = head;
    prev = NULL;

    while (temp != NULL) {
        if (temp->val == val) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}
