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
        return copyRandomListHelper(head, old_new);
    }

    Node* copyRandomListHelper(Node* head, unordered_map<Node*, Node*>& old_new) {
        if(!head) return nullptr;

        auto it = old_new.find(head);
        if(it != old_new.end()) return it->second;

        auto new_node = new Node(head->val);
        old_new[head] = new_node;

        new_node->next = copyRandomListHelper(head->next, old_new);
        new_node->random = copyRandomListHelper(head->random, old_new);

        return new_node;

    }
};
