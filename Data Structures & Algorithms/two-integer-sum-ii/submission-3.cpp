class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        vector<int> result;

        while( left < right ) {
            int num_sum = numbers[left] + numbers[right];
            if( num_sum == target ) {
                result = {++left, ++right};
                return result;
            } else if( num_sum < target ) {
                left++;
                continue;
            } else if( num_sum > target ) {
                right--;
                continue;
            }
        }

        return {-1, -1};
    }
};
