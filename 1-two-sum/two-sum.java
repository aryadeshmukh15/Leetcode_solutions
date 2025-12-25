class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];

            // if complement already seen
            if (map.containsKey(complement)) {
                // return indices here
                return new int[]{map.get(complement), i};
            }
            // store current value with index
            map.put(nums[i], i);
        }
        return new int[] {};
    }
}
