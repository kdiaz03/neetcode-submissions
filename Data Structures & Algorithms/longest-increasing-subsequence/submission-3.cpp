class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if( nums.empty() ) { return -1; };
        const int n = nums.size();
        std::vector<int> subLengths(n, 1);
        int maxSeen = 1;

        for( int i = n - 1; i >= 0; i-- ) {
            for( int j = i + 1; j < n; j++ ) {
                if( nums[i] < nums[j] ) {
                    subLengths[i] = max(subLengths[i], subLengths[j] + 1);
                    maxSeen = max(maxSeen, subLengths[i]);
                }
            }
        }

        return maxSeen;
    }
};

/*
 0 1 2 3 4 5 6
[9,1,4,2,3,3,7]
[1,4,2,3,2,2,1]

*/