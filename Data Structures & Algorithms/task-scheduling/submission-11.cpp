class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for(char task : tasks) freq[task]++;

        priority_queue<int> max_heap;

        for(auto& [task, count] : freq) max_heap.push(count);

        queue<pair<int, int>> q;
        int t = 0;

        while(!max_heap.empty() or !q.empty()){
            t++;
            if(max_heap.empty()){
                t = q.front().second;
            }
            else{
                int curr = max_heap.top();
                max_heap.pop();
                if(--curr) q.push({curr, t+n});
            }

            if(!q.empty() and q.front().second == t){
                max_heap.push(q.front().first);
                q.pop();
            }
        }

        return t;
    }
};
