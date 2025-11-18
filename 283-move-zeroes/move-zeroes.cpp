class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // pointer for position to place next non-zero

        // Step 1: Move all non-zero elements to the front
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }

        // Step 2: Fill remaining positions with zeros
        while(j < nums.size()) {
            nums[j++] = 0;
        }
    }
};
