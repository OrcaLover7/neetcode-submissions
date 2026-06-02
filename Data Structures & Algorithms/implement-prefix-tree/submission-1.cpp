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
            auto& child = curr->children[c];
            if(!child) child = new TrieNode();
            curr = child;
        }

        curr->end_word = true;
    }
    
    bool search(string word) {
        auto curr = root;

        for(char c : word){
            auto& child = curr->children[c];
            if(!child) return false;
            curr = child;
        }

        return curr->end_word == true;
    }
    
    bool startsWith(string prefix) {
        auto curr = root;

        for(char c : prefix){
            auto& child = curr->children[c];
            if(!child) return false;
            curr = child;
        }

        return true;
    }
};
