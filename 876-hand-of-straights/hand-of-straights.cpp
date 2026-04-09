class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) 
        return false;

        sort(hand.begin(), hand.end());

        unordered_map<int, int>freq;

        // count frequency
        for (int num : hand) {
            freq[num]++;
        }

        // try forming groups
        for (int num : hand) {
            if (freq[num] == 0) continue;

            // form group starting from num
            for (int i = 0; i < groupSize; i++) {
                int current = num + i;

                if (freq[current] == 0) {
                    return false;
                }

                freq[current]--;
            }
        }

        return true;
    }
};