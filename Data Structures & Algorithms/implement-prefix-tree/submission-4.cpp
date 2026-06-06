class Trie{
public:
    unordered_map<char, Trie*> children;
    bool is_end = false;
};

class PrefixTree {
    Trie* _root;
public:
    PrefixTree() {
        _root = new Trie();
    }
    
    void insert(string word) {
        auto curr = _root;

        for(char c : word){
            auto& child = curr->children[c];
            if(!child) child = new Trie();

            curr = child;
        }

        curr->is_end = true;
    }
    
    bool search(string word) {
        auto curr = _root;

        for(char c : word){
            auto& childs = curr->children;
            auto it = childs.find(c);

            if(it == childs.end()) return false;

            curr = it->second;
        }

        return curr->is_end;
    }
    
    bool startsWith(string prefix) {
        auto curr = _root;

        for(char c : prefix){
            auto& childs = curr->children;
            auto it = childs.find(c);

            if(it == childs.end()) return false;

            curr = it->second;
        }

        return true;
    }
};
