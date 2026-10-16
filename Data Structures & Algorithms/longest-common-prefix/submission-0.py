class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = min(strs, key=len)

        for word in strs[1:]:
            while not word.startswith(prefix) and prefix:
                prefix = prefix[:-1]
                if not prefix:
                    return ""
        
        return prefix
