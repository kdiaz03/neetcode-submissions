class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;
        int length;

        for( int n : numSet ) {
            if( numSet.contains( n ) ) {
                length = 1;
                while( numSet.contains( n + length ) ) {
                    length++;
                }
                res = max(res, length);
            }
        }

        return res;
    }
};
