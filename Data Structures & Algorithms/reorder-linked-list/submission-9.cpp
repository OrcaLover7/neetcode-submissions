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
        if(!head || !head->next) return;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        slow->next = nullptr;

        ListNode *right = reverse(mid);
        ListNode *left = head;

        while(right){
            ListNode *left_next = left->next;
            ListNode *right_next = right->next;

            left->next = right;
            right->next = left_next;

            left = left_next;
            right = right_next;
        }
        

    }

    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;

        ListNode *curr = head;
        ListNode *prev = nullptr;

        while(curr){
            ListNode* next_curr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_curr;
        }

        return prev;
    }
};
