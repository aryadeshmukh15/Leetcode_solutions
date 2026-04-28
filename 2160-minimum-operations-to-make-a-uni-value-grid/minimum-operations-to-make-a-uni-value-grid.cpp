class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        
        // Flatten grid
        for (auto &row : grid) {
            for (int num : row) {
                arr.push_back(num);
            }
        }

        // Check feasibility
        int base = arr[0];
        for (int num : arr) {
            if ((num - base) % x != 0) return -1;
        }

        // Sort
        sort(arr.begin(), arr.end());

        // Find median
        int n = arr.size();
        int median = arr[n / 2];

        // Count operations
        int ops = 0;
        for (int num : arr) {
            ops += abs(num - median) / x;
        }

        return ops;
    }
};