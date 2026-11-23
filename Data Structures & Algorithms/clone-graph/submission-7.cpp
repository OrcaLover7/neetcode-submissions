/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* clone_helper(Node* node, unordered_map<Node*, Node*>& clones){
        if(!node) return node;

        auto it = clones.find(node);
        if(it != clones.end()) return it->second;

        auto new_node = new Node(node->val);
        clones[node] = new_node;

        for(auto& child : node->neighbors) new_node->neighbors.push_back(clone_helper(child, clones));

        return new_node;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> clones;
        return clone_helper(node, clones);
    }
};
