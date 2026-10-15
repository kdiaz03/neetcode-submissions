class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> s_chars;
        std::unordered_map<char, int> t_chars;

        for (char c : s) {
            if( s_chars.count(c) ) {
                s_chars[c]++;
            } else {
                s_chars[c] = 1;
            }
        }

        for (char c : t) {
            if( t_chars.count(c) ) {
                t_chars[c]++;
            } else {
                t_chars[c] = 1;
            }
        }

        return s_chars == t_chars;
    }
};
