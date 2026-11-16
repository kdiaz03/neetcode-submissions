class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = max(piles)

        min_k = right
        while left <= right:
            kirk = (left + right) // 2
            
            hours = 0
            for p in piles:
                hours += math.ceil(p / kirk)
            
            if hours <= h:
                min_k = kirk
                right = kirk - 1
            else:
                left = kirk + 1

        
        return min_k
