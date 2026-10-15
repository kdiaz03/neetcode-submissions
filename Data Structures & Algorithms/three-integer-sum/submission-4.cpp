#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> triplets;
        int n = static_cast<int>(nums.size());
        
        // 1. Edge case: 3Sum impossible with fewer than 3 elements
        if (n < 3) return triplets;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            // 2. Optimization: If the smallest number is > 0, sum will never be 0
            if (nums[i] > 0) break;

            // 3. Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    
                    // 4. Move both pointers and skip duplicates only after a match
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                }
            }
        }
        return triplets;
    }
};