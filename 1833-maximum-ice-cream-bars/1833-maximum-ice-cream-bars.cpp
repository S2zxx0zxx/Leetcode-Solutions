class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> count(maxCost + 1, 0);
        for (int c : costs) count[c]++;
        
        int bars = 0;
        for (int cost = 1; cost <= maxCost && coins > 0; cost++) {
            if (count[cost] == 0) continue;
            int canBuy = min(count[cost], coins / cost);
            bars += canBuy;
            coins -= canBuy * cost;
        }
        return bars;
    }
};