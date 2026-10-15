class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if( prices.size() < 2 ) {
            return 0;
        }

        int profit = 0;

        int left = 0;
        int right = 1;

        while( (right < prices.size()) && (left < right) ) {
            if( prices[right] <= prices[left] ) {
                left = right;
                right++;
                continue;
            }

            profit = max(profit, prices[right] - prices[left]);

            right++;
        }

        return profit;
    }
};
