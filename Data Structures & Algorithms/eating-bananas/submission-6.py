class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        max_k = max(piles)
        min_k = 1

        result = max_k

        while min_k <= max_k:
            kirk = (max_k + min_k) // 2
            hours = 0
            for p in piles:
                hours += math.ceil(p / kirk)
            if hours <= h:
                result = kirk
                max_k = kirk - 1
            else:
                min_k = kirk + 1
                
        return result