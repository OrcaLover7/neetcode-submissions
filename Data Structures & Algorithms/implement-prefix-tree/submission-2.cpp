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
            auto it  = curr->children.find(c);
            if(it == curr->children.end()) return false;
            curr = it->second;
        }

        return curr->end_word == true;
    }
    
    bool startsWith(string prefix) {
        auto curr = root;

        for(char c : prefix){
            auto it  = curr->children.find(c);
            if(it == curr->children.end()) return false;
            curr = it->second;
        }

        return true;
    }
};
