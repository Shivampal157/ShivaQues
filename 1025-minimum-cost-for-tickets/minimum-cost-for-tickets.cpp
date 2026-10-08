class Solution {
public:
    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if(i >= days.size()) return 0;

        if(dp[i] != -1) return dp[i];

        // 1-day pass
        int one = costs[0] + solve(i + 1, days, costs, dp);

        // 7-day pass
        int j = i;
        while(j < days.size() && days[j] < days[i] + 7) {
            j++;
        }
        int seven = costs[1] + solve(j, days, costs, dp);
        j = i;
        while(j < days.size() && days[j] < days[i] + 30) {
            j++;
        }
        int thirty = costs[2] + solve(j, days, costs, dp);

        return dp[i] = min({one, seven, thirty});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);

        return solve(0, days, costs, dp);
    }
};