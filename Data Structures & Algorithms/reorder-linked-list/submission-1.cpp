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
    //easiest is constructing a new list and replacing head
    //in place?
    void reorderList(ListNode* head) {
        stack<ListNode*> st;

        ListNode* temp = head;

        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        
        temp = head;
        int size = st.size();
        for(int i = 0; i < size/2; i++){
            auto next_temp = temp->next;
            auto right = st.top();
            st.pop();

            temp->next = right;
            right->next = next_temp;

            temp = next_temp;
        }

        temp->next = nullptr;
    }
};
