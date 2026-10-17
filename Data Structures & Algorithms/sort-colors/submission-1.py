class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        bucket_sort = [0 for _ in range(3)]

        for num in nums:
            bucket_sort[num] += 1
        
        idx = 0
        for i in range(3):
            while bucket_sort[i]:
                bucket_sort[i] -= 1
                nums[idx] = i
                idx += 1
            
