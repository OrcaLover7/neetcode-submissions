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

        if(!head || !head->next || !head->next->next) return;

        ListNode* slow, *fast, *prev_slow = nullptr;
        slow = head;
        fast = head;

        while(fast && fast->next){
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev_slow) prev_slow->next = nullptr;

        ListNode* right = reverse(slow);
        ListNode* left = head;

        while(left && right){
            ListNode* left_next = left->next;
            ListNode* right_next = right->next;

            left->next = right;

            if(!left_next) break;
            right->next = left_next;

            left = left_next;
            right = right_next;
        }


    }

    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
