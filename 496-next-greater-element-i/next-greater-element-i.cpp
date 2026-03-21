class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp; // element → next greater
        stack<int> st;

        // Step 1: process nums2
        for(int x : nums2) {

            while(!st.empty() && st.top() < x) {
                mp[st.top()] = x;
                st.pop();
            }

            st.push(x);
        }

        // Step 2: remaining elements → -1
        while(!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // Step 3: build answer
        vector<int> ans;

        for(int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};