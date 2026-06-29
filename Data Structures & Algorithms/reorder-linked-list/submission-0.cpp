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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; 
        
        while (curr) {
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        
        
        ListNode* p1 = head;       
        ListNode* p2 = prev;       
        
        while (p2) {
            ListNode* temp1 = p1->next;
            ListNode* temp2 = p2->next;
            
            
            p1->next = p2;
            p2->next = temp1;
            
            
            p1 = temp1;
            p2 = temp2;
        }
    }
};