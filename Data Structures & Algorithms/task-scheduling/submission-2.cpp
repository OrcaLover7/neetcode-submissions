class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> freq;

        for(char task : tasks) freq[task]++;

        priority_queue<int> max_heap;

        for(auto& [task, frequency] : freq) max_heap.push(frequency);

        int time = 0;

        queue<pair<int, int>> q;

        while(!max_heap.empty() || !q.empty()){
            time++; 

            if(max_heap.empty()) time = q.front().second;
            else {
                auto curr_freq = max_heap.top();
                max_heap.pop();

                curr_freq--;
                if(curr_freq > 0) q.push({curr_freq, time + n});
            }

            if(!q.empty() && q.front().second == time){
                max_heap.push(q.front().first);
                q.pop();
            }
        }

        return time;

    }
};
