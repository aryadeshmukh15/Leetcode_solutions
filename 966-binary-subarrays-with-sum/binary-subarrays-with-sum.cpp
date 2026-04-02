class Solution {
public:

    // Function to count subarrays having sum <= goal
    int atMost(vector<int>& nums, int goal)
    {
        // Edge case
        if(goal < 0) return 0;

        int left = 0;      // left pointer
        int sum = 0;       // current window sum
        int count = 0;     // total valid subarrays

        // Move right pointer
        for(int right = 0; right < nums.size(); right++)
        {
            // Add current element
            sum += nums[right];

            // Shrink window if sum becomes greater than goal
            while(sum > goal)
            {
                sum -= nums[left];
                left++;
            }

            // Add number of valid subarrays ending at right
            count += (right - left + 1);
        }

        return count;
    }


    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        // exact(goal) = atMost(goal) − atMost(goal − 1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};