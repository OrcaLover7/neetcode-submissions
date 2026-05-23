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

        unordered_map<Node*, Node*> otn;
        otn[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(auto child : curr->neighbors){
                auto it = otn.find(child);

                if(it == otn.end()){
                    otn[child] = new Node(child->val);
                    q.push(child);
                }
                otn[curr]->neighbors.push_back(otn[child]);
            }
        }

        return otn[node];
    }
};
