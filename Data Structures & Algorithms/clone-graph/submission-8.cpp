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
        if(!node) return node;
        unordered_map<Node*, Node*> clones;
        clones[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            auto curr_clone = clones[curr];
            for(auto& child : curr->neighbors){
                if(clones.find(child) == clones.end()){
                    clones[child] = new Node(child->val);
                    q.push(child);
                }
                curr_clone->neighbors.push_back(clones[child]);
            }
        }

        return clones[node];
    }
};
