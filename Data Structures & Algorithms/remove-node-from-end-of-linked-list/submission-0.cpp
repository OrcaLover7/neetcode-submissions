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
    //cases - head, tail, any other middle node
    //similar to what we did in lru cache
    //need prev and next at all times
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* prev = nullptr;
        ListNode* temp = head;
        
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }

        int from_start = count-n+1;

        temp = head;

        if(from_start == 1){
            head = temp->next;
            delete temp;
            return head;
        }

        cout << from_start << endl;
        int c = 0;

        while(c < from_start-1){
            prev = temp;
            temp = temp->next;
            c++;
        }

        prev->next = temp->next;

        return head;
    }
};
