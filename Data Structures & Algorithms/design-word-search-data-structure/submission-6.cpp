class Trie{
public:
    unordered_map<char, Trie*> children;
    bool is_word = false;
};

class WordDictionary {
    Trie* _root;
public:
    WordDictionary() {
        _root = new Trie();
    }
    
    void addWord(string word) {
        auto curr = _root;

        for(char c : word){
            auto& child = curr->children[c];
            if(!child) child = new Trie();

            curr = child;
        }

        curr->is_word = true;
    }
    
    bool search(string word) {
        auto curr = _root;

        return srch(word, curr, 0);
    }

    bool srch(string word, Trie* node, int index){
        for(int i = index; i < (int)word.size(); i++){
            char c = word[i];
            auto& childs = node->children;

            if(c == '.'){
                for(auto& [_, child] : childs) if(srch(word, child, i+1)) return true;
                return false;
            }
            else{
                auto it = childs.find(c);

                if(it == childs.end()) return false;

                node = it->second;
            }
        }

        return node->is_word;
    }
};
