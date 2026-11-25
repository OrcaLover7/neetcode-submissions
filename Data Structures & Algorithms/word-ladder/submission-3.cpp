class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.count(endWord) == 0) return 0;

        unordered_set<string> begin_set{beginWord}, end_set{endWord}, visited;

        int len = 1;

        while(!begin_set.empty() and !end_set.empty()){
            if(begin_set.size() > end_set.size()) swap(begin_set, end_set);

            unordered_set<string> next_level;

            for(string word : begin_set){
                for(int i = 0; i < (int)word.size(); i++){
                    char orig = word[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == orig) continue;
                        word[i] = c;

                        if(end_set.count(word)) return len + 1;

                        if(dict.count(word) and !visited.count(word)){
                            visited.insert(word);
                            next_level.insert(word);
                        }
                    }
                    word[i] = orig;
                }
            }
            begin_set = move(next_level);
            len++;
        }


        return 0;
    }
};
