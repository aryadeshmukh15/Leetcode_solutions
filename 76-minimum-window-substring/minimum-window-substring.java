class Solution {
    public String minWindow(String s, String t) {

        // store frequency of characters of t
        HashMap<Character, Integer> freq = new HashMap<>();

        for(char c : t.toCharArray()){
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        int left = 0;

        // number of characters still needed
        int count = t.length();

        int minLen = Integer.MAX_VALUE;
        int start = 0;

        // expand window
        for(int right = 0; right < s.length(); right++){

            char rightChar = s.charAt(right);

            // if character exists in map and needed
            if(freq.containsKey(rightChar) && freq.get(rightChar) > 0){
                count--;
            }

            // decrease frequency
            freq.put(rightChar, freq.getOrDefault(rightChar, 0) - 1);

            // when all characters matched
            while(count == 0){

                // update minimum window
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s.charAt(left);

                // increase frequency while shrinking
                freq.put(leftChar, freq.getOrDefault(leftChar, 0) + 1);

                // if char becomes required again
                if(freq.get(leftChar) > 0){
                    count++;
                }

                left++;
            }
        }

        // if no window found
        if(minLen == Integer.MAX_VALUE){
            return "";
        }

        // return substring
        return s.substring(start, start + minLen);
    }
}