class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # prefix postfix approach
        result = [ 1 for _ in range(len(nums)) ]

        prefix = 1
        for i, num in enumerate(nums):
            result[i] = prefix
            prefix *= num

        postfix = 1
        for i in range(len(nums) - 1, -1, -1):
            result[i] *= postfix
            postfix *= nums[i]

        return result