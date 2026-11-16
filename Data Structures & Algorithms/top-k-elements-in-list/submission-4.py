from heapq import heapify, heappush, heappop
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = {}
        for num in nums:
            if num in counts:
                counts[num] += 1
            else:
                counts[num] = 1
            
        heap = []
        heapify(heap)
        heap_size = k

        for num in counts:
            if heap_size != 0:
                heappush(heap, (counts[num], num))
                heap_size -= 1
            else:
                if counts[num] > heap[0][0]:
                    heappop(heap)
                    heappush(heap, (counts[num], num))
            
        res = []
        for count, num in heap:
            res.append(num)
        
        return res