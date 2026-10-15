class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = { {'(', ')'}, {'{', '}'}, {'[', ']'} };
        stack<char> seen;

        for( char c : s ) {
            if( seen.empty() ) {
                seen.push(c);
                continue;
            }

            if( pairs.contains(c) ) {
                seen.push(c);
            } else {
                for( const auto& [key, value] : pairs ) {
                    if( value == c ) {
                        if( seen.top() == key ) {
                            seen.pop();
                        } else {
                            return false;
                        }
                    }
                }
            }
        }

        return seen.empty();
    }
};