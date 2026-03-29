class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] map = new int[256]; // ASCII characters
        
        // initialize with -1
        for(int i = 0; i < 256; i++){
            map[i] = -1;
        }
        
        int left = 0;
        int maxLen = 0;
        
        for(int right = 0; right < s.length(); right++) {
            
            // if duplicate found
            if(map[s.charAt(right)] >= left) {
                left = map[s.charAt(right)] + 1;
            }
            
            // store index
            map[s.charAt(right)] = right;
            
            // update max length
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
}