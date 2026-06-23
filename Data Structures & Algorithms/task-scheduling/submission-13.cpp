class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        int max_freq = 1;

        for(char task : tasks){
            freq[task]++;
            max_freq = max(max_freq, freq[task]);
        }

        int max_count = 0;

        for(auto& [_, count] : freq) if(count == max_freq) max_count++;
        
        int time = (max_freq-1)*(n+1) + max_count;

        return max((int)tasks.size(), time);


    }
};
