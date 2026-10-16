class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groupings = {}
        res = []

        for s in strs:
            counts = [0 for _ in range(26)]

            for c in s:
                counts[ord(c) - ord('a')] += 1
            
            key = str(counts)

            if key in groupings:
                groupings[key].append(s)
            else:
                groupings[key] = [s]
        
        for key in groupings:
            res.append(groupings[key])

        return res