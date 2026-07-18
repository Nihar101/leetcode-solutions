class MyStack {
public:
    deque<int> p;
    deque<int> st;
    MyStack() {
        return;
    }
    
    void push(int x) {
        st.push_back(x);
    }
    
    int pop() {
        int y = st.back();
        st.pop_back();
        return y;
    }
    
    int top() {
        return st.back();
    }
    
    bool empty() {
        return !st.size();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */