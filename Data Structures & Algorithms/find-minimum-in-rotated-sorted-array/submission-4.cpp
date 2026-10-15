class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = static_cast<int>(nums.size() - 1);

        int minVal = *std::max_element(nums.begin(), nums.end());

        while ( left <= right ) {
            if( nums[left] < nums[right] ) {
                minVal = min(minVal, nums[left]);
                continue;
            }

            int mid = (left + right) / 2;
            if( nums[mid] < nums[right] ){
                right = mid - 1;
            } else {
                left = mid + 1;
            }

            minVal = min(minVal, nums[mid]);
        }

        return minVal;
    }
};
