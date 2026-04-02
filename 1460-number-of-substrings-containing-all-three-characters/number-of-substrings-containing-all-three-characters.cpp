class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();          // length of string
        int left = 0;              // left pointer
        int count = 0;             // answer
        
        vector<int> freq(3, 0);    // freq[0] -> a , freq[1] -> b , freq[2] -> c
        
        // move right pointer
        for(int right = 0; right < n; right++){
            
            // increase frequency of current character
            freq[s[right] - 'a']++;
            
            
            // check if window contains a , b and c
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                
                // if valid, then all substrings from right to end are valid
                count += (n - right);
                
                
                // shrink window from left
                freq[s[left] - 'a']--;
                left++;
            }
        }
        
        return count;
    }
};