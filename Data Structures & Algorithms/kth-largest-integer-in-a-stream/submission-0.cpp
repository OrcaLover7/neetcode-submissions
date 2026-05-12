class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i : nums){
            if(minHeap.size() == k){
                if(minHeap.top() < i){
                    minHeap.pop();
                    minHeap.push(i);
                }
            }
            else minHeap.push(i);
        }
    }
    
    int add(int val) {
        if(minHeap.size() == k){
            if(minHeap.top() < val){
                minHeap.pop();
                minHeap.push(val);
            }
        }
        else{
            minHeap.push(val);
        }

        return minHeap.top();
    }
};
