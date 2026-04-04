class Solution {
public:
    string minWindow(string s, string t) {

        // store frequency of characters in t
        unordered_map<char,int> freq;

        for(char c : t){
            freq[c]++;
        }

        int left = 0;

        // count = how many characters still needed
        int count = t.size();

        // to store minimum window
        int minLen = INT_MAX;

        // starting index of answer
        int start = 0;

        // expand window
        for(int right = 0; right < s.size(); right++){

            // if character exists in t
            if(freq[s[right]] > 0){
                count--;
            }

            // decrease frequency
            freq[s[right]]--;

            // when all characters matched
            while(count == 0){

                // update minimum window
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                // shrink window from left
                freq[s[left]]++;

                // if char becomes required again
                if(freq[s[left]] > 0){
                    count++;
                }

                left++;
            }
        }

        // if no window found
        if(minLen == INT_MAX){
            return "";
        }

        // return minimum window substring
        return s.substr(start, minLen);
    }
};