class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()

        l = 0
        r = len(s) - 1
        while l <= r:
            if( s[r].isalnum() and s[l].isalnum() ):
                if( s[l] != s[r] ):
                    return False
            else:
                if( s[r].isalnum() == False):
                    r -= 1
                    continue
                if( s[l].isalnum() == False ):
                    l += 1
                    continue      
            
            l += 1
            r -= 1
        
        return True
