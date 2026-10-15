class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = static_cast<int>( prices.size() );
        int max_profit = 0;

        if ( n == 1 ) return 0;

        int left = 0;
        for( int right = 1; right < n; right++ ) {
            int profit = prices[right] - prices[left];
            if( profit < 0 ) {
                left = right;
                continue;
            } else {
                max_profit = max(max_profit, profit);
            }
        }

        return max_profit;
    }
};
