#include <string>

class Solution {
public:
    bool isValid(string s) {
        if( s.size() % 2 != 0 ) return false;

        std::string s_stack;
        s_stack.reserve( s.size() );

        for( char c : s ) {
            if( c == '(' ) s_stack.push_back( ')' );
            else if ( c == '{' ) s_stack.push_back( '}' );
            else if ( c == '[' ) s_stack.push_back( ']' );
            else if ( s_stack.empty() || s_stack.back() != c ) return false;
            else s_stack.pop_back();
        }

        return s_stack.empty();
    }
};
