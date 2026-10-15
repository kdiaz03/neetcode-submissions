#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> valid_pairs = {
            {'(',')'},
            {'[',']'},
            {'{','}'}
        };

        std::stack<char> string_char;

        for( char c : s ) {
            auto it = valid_pairs.find( c );

            if( it != valid_pairs.end() ) {
                string_char.push( c );
            } else if ( !string_char.empty() && valid_pairs[ string_char.top() ] == c ) {
                string_char.pop();
            } else {
                return false;
            }
        }

        return (string_char.empty()) ? true : false;
    }
};
