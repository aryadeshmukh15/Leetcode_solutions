class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            unordered_set<char> st;
        
        int left = 0;
        int right = 0;
        int maxLen = 0;
        
        while(right < s.length()) {
            
            // if duplicate found, shrink window
            while(st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            
            // insert current character
            st.insert(s[right]);
            
            // update max length
            maxLen = max(maxLen, right - left + 1);
            
            right++;
        }
        
        return maxLen;   
    }
};