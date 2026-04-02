class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {    
        int n = cardPoints.size();
        
        // total sum of array
        int totalSum = 0;
        for(int num : cardPoints){
            totalSum += num;
        }
        
        // window size
        int windowSize = n - k;
        
        // if k == n
        if(windowSize == 0)
         return totalSum;
        
        int currSum = 0;
        
        // first window sum
        for(int i = 0; i < windowSize; i++){
            currSum += cardPoints[i];
        }
        
        int minSum = currSum;
        
        // sliding window
        for(int i = windowSize; i < n; i++){
            
            currSum += cardPoints[i];
            currSum -= cardPoints[i - windowSize];
            
            minSum = min(minSum, currSum);
        }
        
        // maximum score
        return totalSum - minSum;   
    }
};