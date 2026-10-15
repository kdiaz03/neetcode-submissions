class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if( s.length() == 0 ) {
            return 0; 
        } else if ( s.length() == 1 ) {
            return 1;  
        }

        unordered_set<char> seen;

        int left = 0;
        int right = 1;

        int sub_length = 1;

        while( right < s.length() ) {
            seen.insert(s[left]);
            
            if( (seen.contains(s[right])) ) {
                left++;
                right = left + 1;
                seen.clear();
            } else if ( s[left] != s[right] ){
                sub_length = max(sub_length, right - left + 1);
                seen.insert(s[right]);
                right++;
            } else {
                sub_length = max(sub_length, right - left);
                seen.insert(s[right]);
                right++;
            }
        }

        return sub_length;
    }
};
