class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++)
                if (prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
            return profit;
        }
        
        vector<int> buy(k, INT_MIN), sell(k, 0);
        
        for (int price : prices) {
            for (int i = 0; i < k; i++) {
                buy[i] = max(buy[i], (i == 0 ? 0 : sell[i-1]) - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        
        return sell[k-1];
    }
};