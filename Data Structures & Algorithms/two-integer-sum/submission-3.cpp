class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> indexed;

        for( int i = 0; i < nums.size(); i++ ) {
            int diff = target - nums[i];
            if ( indexed.count( diff ) ) {
                return {indexed[diff], i};
            } else {
                indexed[nums[i]] = i;
            }
        }
    }
};
