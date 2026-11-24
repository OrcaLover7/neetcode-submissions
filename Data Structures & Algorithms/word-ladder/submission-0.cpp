class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_list(wordList.begin(), wordList.end());
        if(word_list.count(endWord) == 0) return 0;

        int n = (int)beginWord.size();

        queue<string> q;
        int len = 1;
        q.push(beginWord);

        while(!q.empty()){
            int sz = (int)q.size();
            for(int i = 0; i < sz; i++){
                auto curr = q.front();
                q.pop();

                if(curr == endWord) return len;

                for(int j = 0; j < (int)curr.size(); j++){
                    char orig = curr[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        curr[j] = c;
                        if(word_list.count(curr)){
                            word_list.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[j] = orig;
                }
            }
            len++;
        }

        return 0;

    }
};
