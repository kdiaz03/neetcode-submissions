class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_idx;
        int n = static_cast<int>( nums.size() );

        num_to_idx.reserve( n );

        for( int i = 0; i < n; i++ ) {
            int complement = target - nums[i];
            auto it = num_to_idx.find( complement );

            if( it != num_to_idx.end() ) {
                return {it->second, i};
            } else {
                num_to_idx[ nums[i] ] = i;
            }
        }

        return {};
    }
};
