class MinStack {
public:
stack<int> st, min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(!min_stack.empty()){
            int top = min_stack.top();
            if(top > val) min_stack.push(val);
            else min_stack.push(top);
        }
        else min_stack.push(val);
    }
    
    void pop() {
        if(!st.empty()){
            int top = st.top();
            st.pop();
            min_stack.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
