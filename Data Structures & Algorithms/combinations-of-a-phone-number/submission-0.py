class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
            
        digit_to_letter = {
            '2': "abc",
            '3': "def",
            '4': "ghi",
            '5': "jkl",
            '6': "mno",
            '7': "pqrs",
            '8': "tuv",
            '9': "wxyz"
        }

        ans = []

        def dfs(start_idx, path_list):
            if start_idx == len(digits):
                ans.append("".join(path_list))
                return
            
            for char in digit_to_letter[digits[start_idx]]:
                path_list.append(char)
                dfs(start_idx + 1, path_list)
                path_list.pop()
            
        dfs(0, [])
        return ans