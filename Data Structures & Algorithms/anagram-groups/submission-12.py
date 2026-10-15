class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groupings = {}

        for s in strs:
            key = "".join(sorted(s))
            if( key in groupings ):
                groupings[key].append(s)
            else:
                groupings[key] = [s]
            
        res = []

        for key in groupings:
            res.append(groupings[key])
        
        return res