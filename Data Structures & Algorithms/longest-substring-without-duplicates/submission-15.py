class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        longest = 0
        l = 0

        for r, char in enumerate(s):
            if char in seen:
                l = max(l, seen[char] + 1)

            seen[char] = r
            longest = max(longest, r - l + 1)

        return longest