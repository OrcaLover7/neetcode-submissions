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
    //immediate thoughts:
    //1. carry happens, what happens? - keep adding to each step until at the end if carry still prevails, create new node and append
    //2. what if one number is smaller than the other? - pick the larger one, keep adding the digits of the larger one until their lengths equate and from then, start actual addition? - wrong, look at order of digits

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        int carry = 0;

        while(l1 || l2 || carry){
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;

            if(l1) l1 = l1->next;

            if(l2) l2 = l2->next;

            int sum = v1+v2+carry;
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
        }

        return dummy.next;
    }
};
