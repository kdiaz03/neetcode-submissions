class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> sumMap;

        int n = nums.size();

        if (nums.size() < 1) {
            return result;
        }

        for( int i = 0; i < n; i++ ) {
            int diff = target - nums[i];
            if( sumMap.contains( diff ) ) {
                result.push_back( sumMap[diff] );
                result.push_back( i );
                return result;
            } else {
                sumMap[ nums[i] ] = i;
            }
        }
    }
};
