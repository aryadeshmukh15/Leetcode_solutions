import java.util.*;

class MyStack {
    Queue<Integer> q1 = new LinkedList<>();
    Queue<Integer> q2 = new LinkedList<>();

    // Push element onto stack
    public void push(int x) {

        // Step 1: push into q2
        q2.offer(x);

        // Step 2: move all elements from q1 → q2
        while(!q1.isEmpty()) {
            q2.offer(q1.poll());
        }

        // Step 3: swap q1 and q2
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    // Removes top element
    public int pop() {
        return q1.poll();
    }

    // Get top element
    public int top() {
        return q1.peek();
    }

    // Check if empty
    public boolean empty() {
        return q1.isEmpty();
    }
}
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */