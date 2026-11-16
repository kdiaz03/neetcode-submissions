class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        if len(arr1) > len(arr2):
            arr1, arr2 = arr2, arr1

        prefix_set = set()
        for val in arr1:
            while val and val not in prefix_set:
                prefix_set.add(val)
                val = val // 10
        
        res = 0
        for val in arr2:
            while val and val not in prefix_set:
                val = val // 10
            
            if val:
                res = max(res, len(str(val)))
            
        return res