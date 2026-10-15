class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while( left < right ) {
            if( numbers[left] + numbers[right] == target ) {
                return {++left, ++right};
            } else if( numbers[left] + numbers[right] < target ) {
                left++;
                continue;
            } else if( numbers[left] + numbers[right] > target ) {
                right--;
                continue;
            }
        }

        return {-1, -1};
    }
};
