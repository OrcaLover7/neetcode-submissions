class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        
        int max_freq = -1;

        for(char task : tasks) freq[task - 'A']++;
        sort(freq.begin(), freq.end());

        max_freq = freq[25];

        int idle = (max_freq-1)*n;

        for(int i = 0; i < 25; i++) idle -= min(freq[i], max_freq-1);

        return max(0, idle) + (int)tasks.size();
    }
};
