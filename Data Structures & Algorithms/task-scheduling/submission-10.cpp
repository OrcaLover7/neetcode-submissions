class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        
        int max_freq = -1;

        for(char task : tasks) freq[task - 'A']++;
        sort(freq.begin(), freq.end());

        max_freq = freq[25];
        int count = 0;

        for(int i = 0; i < 26; i++) if(freq[i] == max_freq) count++;

        int time = (max_freq-1)*(n+1) + count;

        return (max((int)tasks.size(), time)); 
    }
};
