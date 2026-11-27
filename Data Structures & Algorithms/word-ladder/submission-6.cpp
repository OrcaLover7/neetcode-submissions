class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;

        int n = beginWord.size();
        int len = 1;
        unordered_set<string> b{beginWord}, e{endWord}, visited;

        while(!b.empty() and !e.empty()){
            if(b.size() > e.size()) swap(b, e);

            unordered_set<string> next_level;

            for(string word : b){
                for(int i = 0; i < n; i++){
                    char orig = word[i];

                    for(char c = 'a'; c <= 'z'; c++){
                        word[i] = c;
                        
                        if(e.count(word)) return len + 1;
                        if(dict.count(word) and !visited.count(word)){
                            visited.insert(word);
                            next_level.insert(word);
                        }
                    }
                    word[i] = orig;
                }
            }
            len++;
            b = move(next_level);
        }


        return 0;
    }
};
