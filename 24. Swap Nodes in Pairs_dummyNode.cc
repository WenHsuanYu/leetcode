// Using dummyNode
// TC: O(n)
// SC: O(1)
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        // use dummy node 
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* prev = dummyNode;   
        ListNode* curr = head;
        
        while (prev->next && curr->next) {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            prev = curr;
            curr = prev->next;
        }
        
        
        return dummyNode->next;
    }
};