class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while( left <= right ) {
            if( nums[left] == target ) {
                return left;
            }
            if( nums[right] == target ) {
                return right;
            }

            int mid = (left + right) / 2;

            if( nums[mid] == target ) {
                return mid;
            }

            if( nums[left] <= nums[right] ) {
                if( nums[mid] == target ) {
                    return mid;
                } else if( nums[mid] > target ) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
                continue;
            }

            if( target < nums[left] ) {
                left = left + 1;
            } else {
                right = right - 1;
            }
        }

        return -1;
    }
};
