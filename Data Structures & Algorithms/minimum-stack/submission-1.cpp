class MinStack {
public:
stack<pair<int, int>> min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        int min_so_far = min_stack.empty() ? val : min(val, min_stack.top().second);
        min_stack.push({val, min_so_far});
    }
    
    void pop() {
        if(!min_stack.empty())
            min_stack.pop();
    }
    
    int top() {
        return min_stack.top().first;
    }
    
    int getMin() {
        return min_stack.top().second;
    }
};
