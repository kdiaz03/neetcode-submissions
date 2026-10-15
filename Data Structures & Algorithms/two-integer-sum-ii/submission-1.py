class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l , r = 0, len(numbers) - 1

        while l < r:
            carSum = numbers[l] + numbers[r]

            if carSum < target:
                l += 1
                continue
            if carSum > target:
                r -= 1
                continue
            else:
                return [l + 1, r + 1]

        return []