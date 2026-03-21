import java.util.*;

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {

        HashMap<Integer, Integer> map = new HashMap<>();
        Stack<Integer> stack = new Stack<>();

        // Step 1: process nums2
        for(int x : nums2) {

            while(!stack.isEmpty() && stack.peek() < x) {
                map.put(stack.peek(), x);
                stack.pop();
            }

            stack.push(x);
        }

        // Step 2: remaining → -1
        while(!stack.isEmpty()) {
            map.put(stack.peek(), -1);
            stack.pop();
        }

        // Step 3: build answer
        int[] ans = new int[nums1.length];

        for(int i = 0; i < nums1.length; i++) {
            ans[i] = map.get(nums1[i]);
        }

        return ans;
    }
}