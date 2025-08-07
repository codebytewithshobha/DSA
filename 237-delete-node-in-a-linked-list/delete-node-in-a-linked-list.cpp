/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) return; // Safety check
    node->val = node->next->val;
    ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp; // Free memory of the skipped node
}
};