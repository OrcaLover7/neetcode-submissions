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
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> otn;
        return cgHelper(node, otn);
    }

    Node* cgHelper(Node* node, unordered_map<Node*, Node*>& old_to_new){
        if(!node) return nullptr;

        auto it = old_to_new.find(node);
        if(it != old_to_new.end()) return it->second;

        auto curr = new Node(node->val);
        old_to_new[node] = curr;

        for(auto nei : node->neighbors){
            curr->neighbors.push_back(cgHelper(nei, old_to_new));
        }

        return curr;
    }

};
