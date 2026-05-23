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
        return cg(node, otn);
    }

    Node* cg(Node* node, unordered_map<Node*, Node*>& otn){
        if(!node) return nullptr;

        auto it = otn.find(node);
        if(it != otn.end()) return it->second;

        auto new_node = new Node(node->val);
        otn[node] = new_node;

        for(auto child : node->neighbors) new_node->neighbors.push_back(cg(child, otn));

        return new_node;
    }
};
