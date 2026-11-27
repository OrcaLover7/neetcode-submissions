class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;

        queue<string> q;
        int len = 1;
        q.push(beginWord);

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                string curr = q.front();
                q.pop();

                if(curr == endWord) return len;
        
                for(int j= 0; j < curr.size(); j++){
                    char orig = curr[j];

                    for(char c = 'a'; c <= 'z'; c++){
                        curr[j] = c;
                        if(dict.count(curr)){
                            dict.erase(curr);
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
