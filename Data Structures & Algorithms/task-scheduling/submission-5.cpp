class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for(char task : tasks) freq[task]++;
        int max_f = -1;

        for(auto& [_, fr] : freq) max_f = max(max_f, fr);

        int max_count = 0;

        for(auto& [_, fr] : freq) if(max_f == fr) max_count++;

        int time = (max_f-1)*(n+1) + max_count;

        return max((int)tasks.size(), time);
    }
};
