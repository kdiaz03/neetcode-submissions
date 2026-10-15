from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = {}

        for word in strs:
            count = [0] * 26

            for c in word:
                count[ord(c) - ord('a')] += 1
            
            key = tuple(count)

            if key not in anagrams:
                anagrams[key] = []
            
            anagrams[key].append(word)

        return list(anagrams.values())