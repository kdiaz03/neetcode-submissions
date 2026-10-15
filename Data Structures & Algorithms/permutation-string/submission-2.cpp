class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if( s1.length() > s2.length() ) {
            return false;
        }
        
        unordered_map<char, int> input;

        for( char c : s1 ) {
            input[c]++;
        }

        int left = 0;

        for( int right = s1.length() - 1; right < s2.length(); right++ ) {
            unordered_map<char, int> window;

            for( int i = left; i <= right; i++ ) {
                window[s2[i]]++;
            }

            if( input == window ) {
                return true;
            } else {
                left++;
                continue;
            }
        } 

        return false;

    }
};
