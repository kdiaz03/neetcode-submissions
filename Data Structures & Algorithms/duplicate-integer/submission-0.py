class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        duplicates = {}

        for i, num in enumerate(nums):
            if num in duplicates:
                return True
            duplicates[num] = i

        return False