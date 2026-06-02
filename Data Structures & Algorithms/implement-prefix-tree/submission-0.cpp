class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool end_word = false;    
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto curr = root;

        for(char c : word){
            auto& children = curr->children;
            auto it = children.find(c);

            if(it == children.end()){
                children[c] = new TrieNode();
            }
            curr = children[c];
        }

        curr->end_word = true;
    }
    
    bool search(string word) {
        auto curr = root;

        for(char c : word){
            auto& children = curr->children;
            auto it = children.find(c);

            if(it == children.end()) return false;

            curr = it->second;
        }

        return curr->end_word == true;
    }
    
    bool startsWith(string prefix) {
        auto curr = root;

        for(char c : prefix){
            auto& children = curr->children;
            auto it = children.find(c);

            if(it == children.end()) return false;

            curr = it->second;
        }

        return true;
    }
};
