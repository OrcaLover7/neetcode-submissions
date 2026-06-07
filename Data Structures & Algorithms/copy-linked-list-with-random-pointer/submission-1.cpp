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
    unordered_map<Node*, Node*> old_new;
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        auto it = old_new.find(head);
        if(it != old_new.end()) return it->second;

        auto new_node = new Node(head->val);
        old_new[head] = new_node;

        new_node->next = copyRandomList(head->next);
        new_node->random = copyRandomList(head->random);

        return new_node;

    }
};
