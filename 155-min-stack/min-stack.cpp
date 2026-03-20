class MinStack {
public:
    stack<long long> st; // use long long to avoid overflow
    long long minVal;    // current minimum

    MinStack() {}

    // Push element
    void push(int val) {

        // Case 1: first element
        if(st.empty()) {
            st.push(val);
            minVal = val;
        }

        // Case 2: normal push
        else if(val >= minVal) {
            st.push(val);
        }

        // Case 3: new minimum → encode
        else {
            st.push(2LL * val - minVal); // encoded value
            minVal = val;                // update min
        }
    }

    // Pop element
    void pop() {
        long long top = st.top();
        st.pop();

        // If encoded value
        if(top < minVal) {
            // restore previous min
            minVal = 2 * minVal - top;
        }
    }

    // Get top element
    int top() {
        long long top = st.top();

        // If encoded value
        if(top < minVal) {
            return (int)minVal;
        }

        return (int)top;
    }

    // Get minimum
    int getMin() {
        return (int)minVal;
    }
};/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 