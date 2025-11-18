class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0; // position to place next non-zero

        // Step 1: Move non-zero elements to the front
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }

        // Step 2: Fill the remaining positions with zero
        while (j < nums.length) {
            nums[j++] = 0;
        }
    }
}
