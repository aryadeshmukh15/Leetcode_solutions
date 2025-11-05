class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq;  // to store frequencies
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            bool alreadyCounted = false;
            for (int j = 0; j < i; j++) {
                if (arr[i] == arr[j]) {
                    alreadyCounted = true;
                    break;
                }
            }

            if (!alreadyCounted) {
                int count = 0;
                for (int k = 0; k < n; k++) {
                    if (arr[k] == arr[i])
                        count++;
                }
                freq.push_back(count);
            }
        }

        // Check if any two frequencies are equal
        for (int i = 0; i < freq.size(); i++) {
            for (int j = i + 1; j < freq.size(); j++) {
                if (freq[i] == freq[j])
                    return false;
            }
        }

        return true;
    }
};
