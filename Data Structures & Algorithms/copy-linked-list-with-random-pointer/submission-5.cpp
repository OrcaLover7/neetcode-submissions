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
        unordered_map<Node*, Node*> old_new;
        return helper(head, old_new);
    }

    Node* helper(Node* head, unordered_map<Node*, Node*>& old_new){
        if(!head) return nullptr;
        if(old_new.count(head)) return old_new[head];

        auto new_node = new Node(head->val);
        old_new[head] = new_node;
        new_node->next = helper(head->next, old_new);
        new_node->random = helper(head->random, old_new);

        return new_node;

    }
};
