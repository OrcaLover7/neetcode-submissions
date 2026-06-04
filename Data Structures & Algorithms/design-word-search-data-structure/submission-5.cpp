class Trie{
public:
    unordered_map<char, Trie*> children;
    bool is_end = false;
};
class WordDictionary {
    Trie* root;
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        auto curr = root;

        for(char c : word){
            auto& child = curr->children[c];
            if(!child) child = new Trie();

            curr = child;
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        auto curr = root;
        return srch(word, curr, 0);
    }

    bool srch(string word, Trie* curr, int index){
        for(int i = index; i < (int)word.size(); i++){
            if(word[i] == '.'){
                for(auto& [_, child] : curr->children){
                    if(srch(word, child, i+1)) return true;
                }
                return false;
            }
            else{
                auto& children = curr->children;
                auto it = children.find(word[i]);
                if(it == children.end()) return false;
                curr = it->second;
            }
        }

        return curr->is_end;
    }
};
