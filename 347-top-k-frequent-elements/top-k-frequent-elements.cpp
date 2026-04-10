class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Step 1: Count frequency
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }

        // Step 2: Min heap (frequency , number)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Step 3: Push into heap
        for(auto it : freq){
            pq.push({it.second , it.first});

            // Step 4: Keep heap size k
            if(pq.size() > k){
                pq.pop();
            }
        }

        // Step 5: Extract result
        vector<int> result;

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};