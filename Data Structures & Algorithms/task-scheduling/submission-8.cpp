class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char task : tasks) freq[task - 'A']++;

        priority_queue<int> max_heap;

        for(int fr : freq) if(fr > 0 ) max_heap.push(fr);

        queue<pair<int, int>> cd_q;

        int t = 0;

        while(!max_heap.empty() || !cd_q.empty()){
            t++;

            if(max_heap.empty()) t = cd_q.front().second;

            else {
                int curr_freq = max_heap.top();
                max_heap.pop();

                curr_freq--;

                if(curr_freq > 0) cd_q.push({curr_freq, t + n});
            }

            if(!cd_q.empty() and cd_q.front().second <= t){
                max_heap.push(cd_q.front().first);
                cd_q.pop();
            }
        }

        return t;
    }
};
