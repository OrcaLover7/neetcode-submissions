class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool is_ending = false;
};

class WordDictionary {
    TrieNode* _root;
public:
    WordDictionary() {
        _root = new TrieNode();
    }
    
    void addWord(string word) {
        auto curr = _root;

        for(char c : word){
            auto& child = curr->children[c];
            if(!child) child = new TrieNode();
            curr = child;
        }

        curr->is_ending = true;
        
    }
    
    bool search(string word) {
        return search_helper(word, 0, _root);
    }

    bool search_helper(string& word, int index, TrieNode* root){
        if(!root) return false;

        int n = (int)word.size();

        auto curr = root;

        for(int i = index; i < n; i++){
            if(word[i] == '.'){
                for(auto& [_, child] : curr->children) if(search_helper(word, i+1, child)) return true;
                return false;
            }
            else{
                auto& children = curr->children;
                auto it = children.find(word[i]);
                if(it == children.end()) return false;
                curr = it->second;
            }
        }

        return curr->is_ending;
    }
};
