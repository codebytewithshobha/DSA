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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to simplify deletion logic
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Two pointers
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move first pointer n+1 steps ahead to create a gap
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        // Move both pointers until first reaches the end
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        
        // Now, second is pointing to the node before the one to delete
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        
        delete nodeToDelete; // Free memory
        
        // Return the head of the updated list
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
