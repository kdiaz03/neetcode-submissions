class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) <= 1: return

        n = len(nums)

        zero_ptr = 0
        num_ptr = 0

        while num_ptr < n and zero_ptr < n:
            while zero_ptr < n and nums[zero_ptr] != 0:
                zero_ptr += 1
            while num_ptr < n and nums[num_ptr] == 0:
                num_ptr += 1
            
            if zero_ptr < num_ptr < n:
                nums[zero_ptr] = nums[num_ptr]
                nums[num_ptr] = 0
            else:
                num_ptr += 1

            

