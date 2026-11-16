class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        counts = [0 for _ in range(3)]

        for num in nums:
            counts[num] += 1

        print(counts)
        
        idx = 0
        for i in range(3):
            while counts[i]:
                nums[idx] = i
                counts[i] -= 1
                idx += 1