class MinStack {
public:
    stack<int> st;
    stack<int> origSt;
    MinStack() {
        
    }
    
    void push(int value) {
        origSt.push(value);
        if(st.empty()){
            st.push(value);
            return;
        }
        st.push(min(origSt.top(), st.top()));

    }
    
    void pop() {
        st.pop();
        origSt.pop();
    }
    
    int top() {
        return origSt.top();
    }
    
    int getMin() {
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */