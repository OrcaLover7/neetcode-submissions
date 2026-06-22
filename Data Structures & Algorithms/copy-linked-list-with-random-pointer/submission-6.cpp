/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        auto l1 = head;

        while(l1){
            auto l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
            l1 = l2->next;
        }

        auto new_head = head->next;

        l1 = head;

        while(l1){
            if(l1->random) l1->next->random = l1->random->next;
            l1 = l1->next->next;
        }

        l1 = head;

        while(l1){
            auto l2 = l1->next;
            l1->next = l2->next;
            if(l2->next) l2->next = l2->next->next;

            l1 = l1->next;
        }

        return new_head;

    }
};
