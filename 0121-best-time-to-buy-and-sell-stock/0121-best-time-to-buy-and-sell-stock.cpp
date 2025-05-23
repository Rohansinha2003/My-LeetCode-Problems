class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int currentProfit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            currentProfit = max(0, currentProfit + diff);
            profit = max(profit, currentProfit);
        }

        return profit;
    }
};
