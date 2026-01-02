class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Step 1: find pivot
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: find successor in suffix
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: swap pivot and successor
            swap(nums[i], nums[j]);
        }

        // Step 4: reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};
