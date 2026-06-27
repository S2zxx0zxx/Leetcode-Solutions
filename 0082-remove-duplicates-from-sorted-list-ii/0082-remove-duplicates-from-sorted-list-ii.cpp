class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        
        while (prev->next) {
            ListNode* curr = prev->next;
            if (curr->next && curr->val == curr->next->val) {
                int dupVal = curr->val;
                while (prev->next && prev->next->val == dupVal) {
                    prev->next = prev->next->next;
                }
            } else {
                prev = prev->next;
            }
        }
        
        return dummy.next;
    }
};