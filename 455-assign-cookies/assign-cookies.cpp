class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        // Step 1: Sort both arrays
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // Step 2: Two pointers
        int i = 0; // children
        int j = 0; // cookies

        // Step 3: Greedy matching
        while(i < g.size() && j < s.size()) {

            // if cookie satisfies child
            if(s[j] >= g[i]) {
                i++;  // child satisfied
                j++;  // use cookie
            }
            else {
                j++;  // try bigger cookie
            }
        }

        // Step 4: return satisfied children
        return i;
    }
};