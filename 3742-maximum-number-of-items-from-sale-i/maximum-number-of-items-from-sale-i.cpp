class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;
        vector<int> copies(n, 0);
        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (items[j][0] % items[i][0] == 0) {
                    count++;
                }
            }
            copies[i] = count;
        }
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int val = copies[i];
            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + val);
            }
        }
        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / minPrice);
        }
        return ans;
    }
};