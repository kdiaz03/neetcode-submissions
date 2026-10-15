class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freqDict = {}
        for num in nums:
            if num in freqDict:
                freqDict[num] += 1
            else:
                freqDict[num] = 1
        
        sorted_dict = dict(sorted(freqDict.items(), key=lambda item: item[1], reverse=True))
        topKList = [] * k
        keysList = list(sorted_dict.keys())
        print(sorted_dict)
        return keysList[:k]
