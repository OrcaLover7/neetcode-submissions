class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> freq;

        for(char task : tasks) freq[task]++;

        int max_freq = -1;
        char max_elem;

        for(auto& [_, frequency] : freq) {
            if(max_freq < frequency){
                max_freq = frequency;
                max_elem = _;
            }
        }

        int idle = (max_freq-1)*n;

        for(auto& [_, fr] : freq){
            if(_ != max_elem) idle -= min(max_freq-1, fr);
        }

        return (int)tasks.size() + max(0, idle);
    }
};
