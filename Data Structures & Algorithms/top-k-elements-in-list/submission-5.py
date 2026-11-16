from collections import Counter
from heapq import heapify, heappush, heapreplace
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)
        heap = []

        for num, freq in counts.items():
            if len(heap) < k:
                heappush(heap, (freq, num))
            elif freq > heap[0][0]:
                heapreplace(heap, (freq, num))
            
        return [num for freq, num in heap]