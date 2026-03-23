class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int curr : asteroids) {
            bool destroyed = false;

            // resolve all collisions
            while (!st.empty() && st.top() > 0 && curr < 0) {
                if (abs(st.top()) < abs(curr)) {
                    st.pop(); // stack asteroid destroyed
                }
                else if (abs(st.top()) == abs(curr)) {
                    st.pop(); // both destroyed
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true; // current destroyed
                    break;
                }
            }

            // push only if it survives
            if (!destroyed) {
                st.push(curr);
            }
        }

        // convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};