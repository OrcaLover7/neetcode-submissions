class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        int max_freq = 1;
        char max_char;

        for(char task : tasks){
            freq[task]++;
            if(max_freq < freq[task]){
                max_freq = freq[task];
                max_char = task;
            }
        }

        int idle = (max_freq-1)*n;

        for(auto& [task, count] : freq){
            if(task != max_char) idle -= min(max_freq-1, count);
        }

        return (int)tasks.size() + max(0, idle);


    }
};
