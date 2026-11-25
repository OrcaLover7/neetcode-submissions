class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_list(wordList.begin(), wordList.end());
        if(word_list.count(endWord) == 0) return 0;

        queue<string> q;
        q.push(beginWord);
        int len = 1;

        while(!q.empty()){
            int sz = q.size();
            for(int j = 0; j < sz; j++){
                string curr = q.front();
                q.pop();
                if(curr == endWord) return len;

                for(int i = 0; i < (int)curr.size(); i++){
                    char orig = curr[i];

                    for(char c = 'a'; c <= 'z'; c++){
                        curr[i] = c;
                        if(word_list.count(curr)){
                            word_list.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = orig;
                }
            }
            len++;
        }

        return 0;
    }
};
