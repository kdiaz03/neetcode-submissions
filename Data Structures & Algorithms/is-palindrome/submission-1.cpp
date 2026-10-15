class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while( l <= r ) {
            unsigned char left = static_cast<unsigned char>(s[l]);
            unsigned char right = static_cast<unsigned char>(s[r]);

            if( !isalnum(left) ) {
                l++;
                continue;
            } else if( !isalnum(right) ) {
                r--;
                continue;
            }

            left = tolower(left);
            right = tolower(right);

            if( left != right ) {
                return false;
            } else {
                l++;
                r--;
            }
        }

        return true;
    }
};
