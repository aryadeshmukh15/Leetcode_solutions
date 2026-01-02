class Solution {
    private:
    void solve(int index, vector<int>& nums, vector<vector<int>>& ans) {
if (index == nums.size()) {
ans.push_back(nums);
return;
}
for (int i = index; i < nums.size(); i++) {
swap(nums[index], nums[i]);
solve(index + 1, nums, ans);
swap(nums[index], nums[i]); // backtrack
}
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        solve(0,nums,ans);
        return ans;
    }
};