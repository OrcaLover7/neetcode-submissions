class KthLargest {
    int _k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;

        for(int i : nums){
            if(minHeap.size() == k){
                if(i > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(i);
                }
            }
            else minHeap.push(i);
        }
    }
    
    int add(int val) {
        if(minHeap.size() == _k){
            if(val > minHeap.top()){
                minHeap.pop();
                minHeap.push(val);
            }       
        }
        else minHeap.push(val);

        return minHeap.top();
    }
};
