class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            // profit if sold today
            maxProfit = max(maxProfit, prices[i] - minPrice);

            // update minimum buying price
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};
