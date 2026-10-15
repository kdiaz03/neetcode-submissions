class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()

        l = 0
        r = len(s) - 1
        while l <= r: 
            if( s[l].isalnum() == False ):
                l += 1
                continue
            if( s[r].isalnum() == False ):
                r -= 1
                continue
            
            if( s[r] != s[l] ):
                return False
            
            r -= 1
            l += 1
        
        return True