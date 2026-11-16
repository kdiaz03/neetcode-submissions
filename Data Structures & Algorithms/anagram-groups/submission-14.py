class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groupings = {}

        for word in strs:
            count = [0 for _ in range(26)]
            for c in word:
                count[ord(c) - ord('a')] += 1
            
            key = str(count)

            if key in groupings:
                groupings[key].append(word)
            else:
                groupings[key] = [word]
            
        res = []
        for key in groupings:
            res.append(groupings[key])
        
        return res

            