class Solution {
public:
    // i think it's like this: 
    // 1. if you see an operand -> push to stack
    // 2. if not, get hte last 2 from stack perfrom the current operation and push back to stack. 
    // 3. keep doing until you reach end of the string. whatever is at top of stack is your answer
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> operators = {"*", "-", "/", "+"};

        for(auto& token : tokens){
            if(!operators.count(token)) st.push(stoi(token));
            else{
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int calc;

                if(token == "*"){
                    calc = a*b;
                }else if(token == "/"){
                    calc = a/b;
                }else if(token == "-"){
                    calc = a-b;
                }
                else{
                    calc = a+b;
                }

                st.push(calc);
            }
        }

        return st.top();
    }
};
