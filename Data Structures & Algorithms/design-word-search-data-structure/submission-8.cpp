class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool is_word = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for(char c : word){
            auto& child = curr->children[c];
            if(!child) child = new TrieNode();

            curr = child;
        }

        curr->is_word = true;
    }
    
    bool search(string word) {
        auto curr = root;
        return srch(curr, word, 0);
    }

    bool srch(TrieNode* node, const string& word, int index){
        for(int i = index; i < (int)word.size(); i++){
            char curr = word[i];
            if(curr == '.'){
                for(auto [_, child] : node->children) if(srch(child, word, i+1)) return true;
                return false;
            }
            else{
                auto childs = node->children;
                auto it = childs.find(curr);

                if(it == childs.end()) return false;

                node = it->second;
            }
        }

        return node->is_word;
    }
};
