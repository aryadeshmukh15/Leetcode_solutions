import java.util.*;

class MinStack {

    Stack<Long> st;   // use long to avoid overflow
    long min;         // current minimum

    public MinStack() {
        st = new Stack<>();
    }

    // Push element
    public void push(int val) {

        // Case 1: first element
        if(st.isEmpty()) {
            st.push((long)val);
            min = val;
        }

        // Case 2: normal value
        else if(val >= min) {
            st.push((long)val);
        }

        // Case 3: new minimum → encode
        else {
            long encoded = 2L * val - min;
            st.push(encoded);
            min = val; // update min
        }
    }

    // Pop element
    public void pop() {

        long top = st.pop();

        // If encoded value
        if(top < min) {
            // restore previous minimum
            min = 2 * min - top;
        }
    }

    // Get top element
    public int top() {

        long top = st.peek();

        // If encoded → actual value is min
        if(top < min) {
            return (int)min;
        }

        return (int)top;
    }

    // Get minimum
    public int getMin() {
        return (int)min;
    }
}