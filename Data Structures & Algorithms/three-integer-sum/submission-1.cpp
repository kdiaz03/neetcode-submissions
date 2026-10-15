class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for( int n : nums) {
            cout << n << endl;
        }

        vector<vector<int>> triplets;

        for( int i = 0; i < nums.size(); i++ ) {
            if( (i > 0) && (nums[i] == nums[i - 1]) ) {
                continue;
            }

            int currNum = nums[i];
            
            int left = i + 1;
            int right = nums.size() - 1;

            while( left < right ) {
                int threeSum = currNum + nums[left] + nums[right];

                if( threeSum < 0 ) {
                    left++;
                    while( (nums[left] == nums[left - 1]) && (left < right) ) {
                        left++;
                    }
                } else if ( threeSum > 0 ) {
                    right--;
                    while ( (right < nums.size() - 2) && (nums[right] == nums[right + 1]) && (right > left) ) {
                        right--;
                    }
                } else if ( threeSum == 0 ) {
                    triplets.push_back( {currNum, nums[left], nums[right]} );
                    left++;
                    while( (nums[left] == nums[left - 1]) && (left < right) ) {
                        left++;
                    }
                }
            }
        }
        return triplets;
    }
};
