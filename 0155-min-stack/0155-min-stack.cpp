class MinStack {
public:
    stack<pair<int,int>> st; // {val, currentMin}
    
    MinStack() {}
    
    void push(int val) {
        int minVal = st.empty() ? val : min(val, st.top().second);
        st.push({val, minVal});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};