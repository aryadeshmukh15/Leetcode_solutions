class Solution {
    public int[] nextGreaterElements(int[] nums) {
        
        int n = nums.length;
        
        // Result array initialized with -1 (default when no greater element exists)
        int[] result = new int[n];
        Arrays.fill(result, -1);

        // Stack will store indices (not values)
        Stack<Integer> stack = new Stack<>();

        // Traverse array twice to simulate circular behavior
        for (int i = 0; i < 2 * n; i++) {

            // Use modulo to wrap around (circular array)
            int current = nums[i % n];

            // If current element is greater than element at index on top of stack
            // then it is the next greater element for that index
            while (!stack.isEmpty() && nums[stack.peek()] < current) {
                int index = stack.pop();     // index whose answer we found
                result[index] = current;     // update result
            }

            // Push index only in first pass
            // Second pass is just for resolving remaining elements
            if (i < n) {
                stack.push(i);
            }
        }

        return result;
    }
}