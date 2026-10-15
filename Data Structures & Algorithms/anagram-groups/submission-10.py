class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groupings = {}

        for s in strs:
            counts = [0 for _ in range(26)]

            for c in s:
                counts[ord(c) - ord('a')] += 1
            
            key = ""
            for num in counts:
                key += str(num) + "#"

            if key not in groupings:
                groupings[key] = [s]
            else:
                groupings[key].append(s)

        results = []
        for key in groupings:
            results.append(groupings[key])
        
        return results