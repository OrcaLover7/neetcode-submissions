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
        
        ListNode dummy(0, head);
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;

        int k = 0;
        while(k++ < n){
            fast = fast->next;
        }

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* to_del = slow->next;
        slow->next = slow->next->next;

        delete to_del;

        return dummy.next;
    }
};
