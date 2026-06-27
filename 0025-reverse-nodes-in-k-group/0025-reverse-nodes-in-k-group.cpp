class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        int count = 0;
        while (node && count < k) {
            node = node->next;
            count++;
        }
        
        if (count < k) return head;
        
        ListNode* prev = reverseKGroup(node, k);
        ListNode* curr = head;
        
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};