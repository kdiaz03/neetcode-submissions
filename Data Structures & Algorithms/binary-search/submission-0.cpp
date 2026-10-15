class Solution {
public:
    int search(vector<int>& nums, int target) {
        if( nums.size() == 1 ) {
            if( nums[0] == target ) {
                return 0;
            } else {
                return -1;
            }
        }

        int left = 0;
        int right = static_cast<int>( nums.size() - 1 );
        int middle;

        while( left <= right ) {
            middle = (left + right) / 2;

            if( nums[middle] == target ) {
                return middle;
            } else if( nums[middle] < target ) {
                left = middle + 1;
                continue;
            } else if( nums[middle] > target ) {
                right = middle - 1;
                continue;
            }
        }

        return -1;
    }
};
